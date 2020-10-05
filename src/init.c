/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:46:16 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/09/08 15:05:51 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	initialize2(t_lemin *lemin)
{
	lemin->fd = 0;
	lemin->flags[0] = 0;
	lemin->flags[1] = 0;
	lemin->flags[2] = 0;
	lemin->tmp = NULL;
	lemin->tmp2 = NULL;
	lemin->path_moves = NULL;
	lemin->currentnode = 0;
	lemin->moves = ft_strnew(0);
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->paths = NULL;
	lemin->line = NULL;
	lemin->result_paths = NULL;
}

void	initialize(t_lemin *lemin)
{
	lemin->start_links = 0;
	lemin->end_links = 0;
	lemin->ants = 0;
	lemin->round = 1;
	lemin->req = -1;
	lemin->start_end = 0;
	lemin->short_path = 0;
	lemin->i = 0;
	lemin->i2 = 0;
	lemin->current = 0;
	lemin->count = 0;
	lemin->path2_moves = 0;
	lemin->count_ants = 1;
	lemin->rooms = 0;
	lemin->lines = 1;
	lemin->amount = 0;
	lemin->length = 0;
	lemin->check_end = 0;
	lemin->check_start = 0;
	initialize2(lemin);
}

void	init_id(t_lemin *lemin, t_room *room)
{
	t_room	*tmp;
	int		id;

	tmp = room;
	id = 0;
	while (tmp)
	{
		tmp->number = id;
		id++;
		tmp = tmp->next;
	}
	lemin->start_id = find_room(room, lemin->start)->number;
	lemin->end_id = find_room(room, lemin->end)->number;
}

void	init_link(t_lemin *lemin, t_room *room, char **links)
{
	check_path(lemin, links);
	room = link_rooms(room, links[0], links[1]);
	room = link_rooms(room, links[1], links[0]);
	free_2d_array(links);
}

void	reset_visit_values(t_lemin *lemin, t_room *tmp, char **arr, char *str)
{
	while (tmp)
	{
		if (search_name(lemin, arr, tmp->name) == 1)
		{
			if ((lemin->round == 2 && tmp->visited !=
				lemin->round - 1) || lemin->round == 1)
				tmp->visited = -1;
			else
				tmp->visited = 1;
		}
		tmp = tmp->next;
	}
	free_2d_array(arr);
	free(str);
}
