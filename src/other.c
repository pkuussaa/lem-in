/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:34:13 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 12:49:58 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		search_name(t_lemin *lemin, char **arr, char *name)
{
	int		y;

	y = 0;
	if (name[0] == '\0')
		return (0);
	while (arr[y])
	{
		if (arr[y][0] != '\0')
		{
			if (ft_strcmp(name, lemin->start) == 0 ||
					ft_strcmp(name, lemin->end) == 0)
				return (1);
			if (ft_strcmp(arr[y], name) == 0)
				return (0);
		}
		y++;
	}
	return (1);
}

int		get_l(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	*get_str(char **arr, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strnew(0);
	while (arr[i])
	{
		if (arr[i][0] != '#')
		{
			tmp = ft_strjoin(tmp2, arr[i]);
			ft_strdel(&tmp2);
			tmp2 = ft_strdup(tmp);
			ft_strdel(&tmp);
			if (arr[i + 1] != NULL)
			{
				tmp = ft_strjoin(tmp2, " ");
				ft_strdel(&tmp2);
				tmp2 = ft_strdup(tmp);
				ft_strdel(&tmp);
			}
		}
		i++;
	}
	free_2d_array(arr);
	return (tmp2);
}

void	init_array(t_lemin *lemin)
{
	int		i;
	int		x;

	i = 0;
	if (!(lemin->int_paths = (int**)malloc(sizeof(int*) * lemin->rooms)))
		exit_error();
	while (i < lemin->rooms)
	{
		x = 0;
		lemin->int_paths[i] = (int*)malloc(sizeof(int) * 500);
		while (x <= 500)
		{
			if (x == 0)
				lemin->int_paths[i][x] = lemin->start_room->number;
			else
				lemin->int_paths[i][x] = -1;
			x++;
		}
		i++;
	}
}

int		find_empty(int **str)
{
	int		y;

	y = 0;
	while (str[y])
	{
		if (str[y][1] == -1)
			return (y);
		y++;
	}
	return (0);
}
