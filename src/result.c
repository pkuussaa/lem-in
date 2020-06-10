/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:17:55 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/10 14:25:58 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	init_optimization_variables(t_lemin *lemin, t_room *room)
{
	t_room	*temp;

	lemin->count = get_path_count(lemin->result_paths);
	lemin->path_moves = init_moves(lemin->path_moves, lemin->ants);
	lemin->tmp = ft_strdup(get_first_path_node(lemin->result_paths[0]));
	temp = find_room(room, get_first_path_node(lemin->result_paths[0]));
	temp->count++;
	lemin->path_moves[lemin->i2] =
	display_format(lemin->tmp, ft_itoa(lemin->count_ants));
	ft_strdel(&lemin->tmp);
}

void	optimization1(t_lemin *lemin, t_room *room)
{
	lemin->i2 = get_next_move(lemin->path_moves, get_first_path_node(lemin->
	result_paths[get_next_path(lemin->result_paths, lemin->current)]), 0);
	lemin->tmp = display_format(get_first_path_node(lemin->
	result_paths[get_next_path(lemin->result_paths, lemin->current)]),
	ft_itoa(lemin->count_ants + 1));
	lemin->count_ants++;
	if (lemin->path_moves[lemin->i2][0] != '\0')
	{
		lemin->tmp = ft_strjoin(" ", lemin->tmp);
		lemin->path_moves[lemin->i2] =
		ft_strjoin(lemin->path_moves[lemin->i2], lemin->tmp);
	}
	else
		lemin->path_moves[lemin->i2] = ft_strdup(lemin->tmp);
	ft_strdel(&lemin->tmp);
	find_room(room, get_first_path_node(lemin->result_paths[
	get_next_path(lemin->result_paths, lemin->current)]))->count++;
	lemin->current = get_next_path(lemin->result_paths, lemin->current);
}

void	optimization2(t_lemin *lemin, t_room *room)
{
	lemin->i2 = get_next_move(lemin->path_moves,
	get_first_path_node(lemin->result_paths[0]), 0);
	lemin->tmp = display_format(get_first_path_node(
	lemin->result_paths[0]), ft_itoa(lemin->count_ants + 1));
	lemin->count_ants++;
	if (lemin->path_moves[lemin->i2][0] != '\0')
	{
		lemin->tmp = ft_strjoin(" ", lemin->tmp);
		lemin->path_moves[lemin->i2] =
		ft_strjoin(lemin->path_moves[lemin->i2], lemin->tmp);
	}
	else
		lemin->path_moves[lemin->i2] = ft_strdup(lemin->tmp);
	ft_strdel(&lemin->tmp);
	find_room(room, get_first_path_node(lemin->result_paths[0]))->count++;
	lemin->current = 0;
}

void	optimization3(t_lemin *lemin, t_room *room)
{
	lemin->i2 = get_next_move(lemin->path_moves,
	get_first_path_node(lemin->result_paths[lemin->current]), 0);
	lemin->tmp = display_format(get_first_path_node(
	lemin->result_paths[lemin->current]), ft_itoa(lemin->count_ants + 1));
	lemin->count_ants++;
	if (lemin->path_moves[lemin->i2][0] != '\0')
	{
		lemin->tmp = ft_strjoin(" ", lemin->tmp);
		lemin->path_moves[lemin->i2] =
		ft_strjoin(lemin->path_moves[lemin->i2], lemin->tmp);
	}
	else
		lemin->path_moves[lemin->i2] = ft_strdup(lemin->tmp);
	find_room(room, get_first_path_node(
	lemin->result_paths[lemin->current]))->count++;
}

void	optimizate_paths_to_use(t_lemin *lemin, t_room *room)
{
	init_optimization_variables(lemin, room);
	while (lemin->count_ants < lemin->ants)
	{
		if (find_room(room, get_first_path_node(lemin->result_paths[lemin->
		current]))->count + path_length(lemin->result_paths[lemin->current]) >
		find_room(room, get_first_path_node(lemin->result_paths[get_next_path(
		lemin->result_paths, lemin->current)]))->count + path_length(lemin->
		result_paths[get_next_path(lemin->result_paths, lemin->current)]))
			optimization1(lemin, room);
		else if (ft_strcmp(lemin->result_paths[0], lemin->result_paths[lemin->
		current]) != 0 && find_room(room, get_first_path_node(lemin->
		result_paths[lemin->current]))->count + path_length(lemin->result_paths[
		lemin->current]) > find_room(room, get_first_path_node(lemin->
		result_paths[0]))->count + path_length(lemin->result_paths[0]))
			optimization2(lemin, room);
		else
			optimization3(lemin, room);
	}
	lemin->paths = lemin->path_moves;
}
