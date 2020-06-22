/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/22 15:08:26 by pkuussaa         ###   ########.fr       */
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

int		loop_links(t_lemin *lemin, t_queue *queue, t_room *room)
{
	t_link	*links;
	char	*tmp;

	links = find_room(room, lemin->currentnode)->links;
	while (links)
	{
		if (links->room_link->visited == 0)
		{
			if (lemin->length == 1)
				lemin->i = current_index(lemin, lemin->currentnode);
			tmp = ft_strdup(lemin->paths[lemin->i]);
			free(lemin->paths[lemin->i]);
			lemin->paths[lemin->i] = init_str(lemin,
			tmp, links->room_link->name);
			ft_strdel(&tmp);
			links->room_link->visited = 1;
			enqueue(queue, links->room_link->name);
		}
		if (ft_strcmp(links->room_link->name, lemin->end) == 0)
		{
			free(lemin->currentnode);
			return (1);
		}
		if (!links->next)
			break ;
		if (lemin->length == 0)
			lemin->i++;
		links = links->next;
	}
	free(lemin->currentnode);
	return (0);
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
		if (loop_links(lemin, queue, room) == 1)
			break ;
		lemin->length = 1;
	}
	if (save_and_clear(lemin, room, lemin->i) == 1)
	{
		find_paths(lemin, room);
	}
	free_items(queue->items, lemin->rooms);
	free(queue);
}
