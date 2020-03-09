/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/09 18:55:43 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	find_paths(t_lemin *lemin, t_room *room, t_room *tmp)
{
	t_room	*tmp;
	t_link	*link_tmp;

	link_tmp = room->links;
	tmp = room;
	while (link_tmp)
	{
		link_tmp->visited = 1;
	}
	if (tmp->next)
		find_paths(lemin, room, find_room(room, ));
}
