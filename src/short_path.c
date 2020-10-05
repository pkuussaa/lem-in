/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 11:50:27 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/09/30 16:33:17 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	if_short_path(t_lemin *lemin)
{
	if (lemin->currentnode ==
	lemin->start_id && lemin->short_path == 1)
		lemin->end_room->visited = 2;
	else
		lemin->end_room->visited = -1;
}

int		short_path_return(t_lemin *lemin)
{
	if (lemin->currentnode == lemin->start_id && lemin->short_path == 0)
	{
		lemin->short_path = 1;
		return (1);
	}
	if (lemin->currentnode != lemin->start_id)
		return (1);
	return (0);
}

void	count_start_end_links(t_lemin *lemin)
{
	int		count;
	t_link	*links;

	count = 0;
	links = lemin->start_room->links;
	while (links)
	{
		links = links->next;
		count++;
	}
	lemin->start_links = count;
	count = 0;
	links = lemin->end_room->links;
	while (links)
	{
		links = links->next;
		count++;
	}
	lemin->end_links = count;
}

int		get_result_path_count(char **arr)
{
	int		i;

	i = 0;
	while (arr[i][0] != '\0')
		i++;
	return (i);
}

int		check_if_more_paths(t_lemin *lemin)
{
	char	**arr;

	arr = lemin->round == 1 ? lemin->result_paths : lemin->result_paths2;
	if (get_result_path_count(arr) == lemin->start_links ||
	get_result_path_count(arr) == lemin->end_links)
		return (0);
	return (1);
}
