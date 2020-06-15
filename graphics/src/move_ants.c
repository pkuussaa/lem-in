/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:43:16 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/15 16:17:35 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		get_ant(char *str)
{
	return (ft_atoi(ft_strsplit(str + 1, '-')[0]));
}

char	*get_room_name(char *str)
{
	return (ft_strsplit(str, '-')[1]);
}

t_ants	*find_ant(t_ants **ants, int name)
{
	int		i;

	i = 0;
	while (ants[i])
	{
		if (ants[i]->name == name)
			return (ants[i]);
		i++;
	}
	return (NULL);
}

double	**loop_and_init(t_graphics *info, double **arr, int y, int i)
{
	while (info->result[y][i])
	{
		arr[i] = get_coord(handle_link(info->room, init_char(find_ant(info->ant,
		get_ant(info->result[y][i]))->room_name,
		get_room_name(info->result[y][i]))));
		find_ant(info->ant, get_ant(info->result[y][i]))->room_name =
		get_room_name(info->result[y][i]);
		i++;
	}
	return (arr);
}

int		move_ants(t_graphics *info, t_ants **ants)
{
	int			y;
	int			count;
	double		**arr;

	y = 0;
	if (!info->result[y])
		return (-1);
	while (info->result[y])
	{
		count = 0;
		while (info->result[y][count])
			count++;
		if (!(arr = (double**)malloc(sizeof(double*) * count)))
			exit(EXIT_FAILURE);
		arr = loop_and_init(info, arr, y, 0);
		info->ant_moves[y] = arr;
		y++;
	}
	return (0);
}
