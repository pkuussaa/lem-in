/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 12:31:30 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_next_slot(t_lemin *lemin, int node)
{
	int		y;
	int		i;
	int		res;

	y = -1;
	i = -1;
	res = 0;
	while (lemin->int_paths[++i])
	{
		while (++y < 500)
			if (lemin->int_paths[i][y] == node)
			{
				res = find_empty(lemin->int_paths);
				init_next_slot(lemin, i, res);
				return (res);
			}
		y = -1;
	}
	return (0);
}

int		current_index(t_lemin *lemin, int str)
{
	int		i;
	int		y;
	int		node;

	y = 0;
	i = 0;
	node = str;
	while (i < lemin->rooms)
	{
		while (y < 500)
		{
			if (lemin->int_paths[i][y] == node &&
			lemin->int_paths[i][y + 1] == -1)
				return (i);
			if (lemin->int_paths[i][y] == -1)
				break ;
			y++;
		}
		y = 0;
		i++;
	}
	return (get_next_slot(lemin, node));
}

void	if_not_visited(t_lemin *lemin, t_queue *queue,
							t_link *links)
{
	int		i;

	i = 0;
	lemin->i = current_index(lemin, lemin->currentnode);
	while (lemin->int_paths[lemin->i][i] != -1)
		i++;
	lemin->int_paths[lemin->i][i] =
	links->room_link->number;
	if (links->room_link->visited == -1)
		links->room_link->visited = lemin->round;
	else if (links->room_link->visited == 1 && lemin->round == 2)
		links->room_link->visited = 3;
	enqueue(queue, links->room_link->number);
}

int		loop_links(t_lemin *lemin, t_queue *queue, t_room *room)
{
	t_link	*links;

	links = find_room_with_number(room, lemin->currentnode)->links;
	if_short_path(lemin);
	while (links)
	{
		if (links->room_link->visited == -1 ||
		(links->room_link->visited == lemin->round - 1 &&
		find_room_with_number(room, lemin->currentnode)->visited
		== lemin->round && lemin->round > 1))
			if_not_visited(lemin, queue, links);
		if (links->room_link->number == lemin->end_room->number)
			if (short_path_return(lemin) == 1)
				return (1);
		if (!links->next)
			break ;
		links = links->next;
	}
	return (0);
}

void	find_paths(t_lemin *lemin, t_room *room)
{
	t_queue		*queue;

	queue = init_queue(lemin);
	init_array(lemin);
	lemin->start_room->visited = lemin->round;
	enqueue(queue, lemin->start_room->number);
	while (!is_empty(queue))
	{
		lemin->currentnode = dequeue(queue);
		if (loop_links(lemin, queue, room) == 1)
			break ;
	}
	if (save_and_clear(lemin, room, lemin->i) == 1)
		if (check_if_more_paths(lemin) == 1)
			find_paths(lemin, room);
	free_items(queue->items);
	free(queue);
}
