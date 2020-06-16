/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 12:30:37 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_next_slot(t_lemin *lemin, char *str)
{
	int		y;
	int		i;
	int		res;
	char	**arr;

	y = -1;
	i = -1;
	res = 0;
	while (lemin->paths[++i])
	{
		arr = ft_strsplit(lemin->paths[i], '-');
		while (arr[++y])
			if (ft_strcmp(arr[y], str) == 0)
			{
				res = find_empty(lemin, lemin->paths);
				ft_strdel(&lemin->paths[res]);
				lemin->paths[res] = cut_last_node(lemin->paths[i]);
				free_2d_array(arr);
				return (res);
			}
		y = -1;
		free_2d_array(arr);
	}
	return (0);
}

int		current_index(t_lemin *lemin, char *str)
{
	char	**arr;
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (lemin->paths[i])
	{
		arr = ft_strsplit(lemin->paths[i], '-');
		while (arr[y])
		{
			if (ft_strcmp(arr[y], str) == 0 && !arr[y + 1])
			{
				free_2d_array(arr);
				return (i);
			}
			y++;
		}
		y = 0;
		free_2d_array(arr);
		i++;
	}
	return (get_next_slot(lemin, str));
}

t_link	*loop_links(t_lemin *lemin, t_link *links, t_queue *queue)
{
	while (links)
	{
		if (links->room_link->visited == 0)
		{
			if (lemin->length == 1)
				lemin->i = current_index(lemin, lemin->currentnode);
			lemin->paths[lemin->i] = init_str(lemin,
			lemin->paths[lemin->i], links->room_link->name);
			links->room_link->visited = 1;
			enqueue(queue, links->room_link->name);
		}
		if (!links->next)
			break ;
		if (lemin->length == 0)
			lemin->i++;
		links = links->next;
	}
	ft_strdel(&lemin->currentnode);
	return (links);
}

void	find_paths(t_lemin *lemin, t_room *room)
{
	t_queue		*queue;
	t_link		*links;

	queue = init_queue(queue, lemin);
	ft_printf("");
	lemin->paths = init_array(lemin, find_room(room, lemin->start)->name);
	find_room(room, lemin->start)->visited = 1;
	enqueue(queue, find_room(room, lemin->start)->name);
	while (!is_empty(queue))
	{
		lemin->currentnode = dequeue(queue);
		links = find_room(room, lemin->currentnode)->links;
		links = loop_links(lemin, links, queue);
		lemin->length = 1;
		if (ft_strcmp(links->room_link->name, lemin->end) == 0)
			break ;
	}
	if (save_and_clear(lemin, room, lemin->i) == 1)
		find_paths(lemin, room);
	free_items(queue->items, lemin->rooms);
	free(queue);
}
