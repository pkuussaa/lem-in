/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_path_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:38:04 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 13:54:28 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_req(t_lemin *lemin)
{
	int		i;
	int		y;
	char	**tmp;

	i = 0;
	lemin->path1_sum = 0;
	while (lemin->result_paths[i][0] != '\0')
		i++;
	lemin->path1_lines = i;
	i = -1;
	while (lemin->result_paths[++i][0] != '\0')
	{
		y = 0;
		tmp = ft_strsplit(lemin->result_paths[i], '-');
		while (tmp[y])
			y++;
		lemin->path1_sum += (y - 2);
		free_2d_array(tmp);
	}
	lemin->path1_moves = ((lemin->path1_sum + lemin->ants)
	/ lemin->path1_lines) + ((lemin->path1_sum + lemin->ants)
	% lemin->path1_lines ? 1 : 0);
	if (lemin->req == -1)
		return (1);
	return (lemin->path1_moves > lemin->req + 9);
}

void	count_path2(t_lemin *lemin)
{
	int		i;
	int		y;
	char	**tmp;

	i = 0;
	lemin->path2_sum = 0;
	if (lemin->result_paths2[0][0] == '\0')
		return ;
	while (lemin->result_paths2[i][0] != '\0')
		i++;
	lemin->path2_lines = i;
	i = 0;
	while (lemin->result_paths2[i][0] != '\0')
	{
		y = 0;
		tmp = ft_strsplit(lemin->result_paths2[i], '-');
		while (tmp[y])
			y++;
		lemin->path2_sum += y - 2;
		free_2d_array(tmp);
		i++;
	}
	lemin->path2_moves =
	((lemin->path2_sum + lemin->ants) / lemin->path2_lines) +
	((lemin->path2_sum + lemin->ants) % lemin->path2_lines ? 1 : 0);
}

void	init_round2(t_lemin *lemin, t_room *rooms)
{
	if (!(lemin->result_paths2 =
	(char**)malloc(sizeof(char*) * lemin->rooms)))
		exit_error();
	lemin->result_paths2[0] = NULL;
	lemin->round++;
	lemin->last = 0;
	find_paths(lemin, rooms);
	count_path2(lemin);
	if (lemin->path1_moves < lemin->path2_moves || lemin->path2_moves == 0)
		free_result_path(lemin->result_paths2, lemin->path2_lines);
	else
	{
		free_result_path(lemin->result_paths, lemin->path1_lines);
		lemin->result_paths = lemin->result_paths2;
	}
}
