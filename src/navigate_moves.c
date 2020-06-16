/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigate_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:25:43 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 17:44:51 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*display_format(char *room, char *number)
{
	char	*tmp;

	tmp = ft_strjoin("L", number);
	ft_strdel(&number);
	number = ft_strjoin(tmp, "-");
	ft_strdel(&tmp);
	tmp = ft_strjoin(number, room);
	ft_strdel(&number);
	ft_strdel(&room);
	return (tmp);
}

char	**init_moves(char **arr, int i)
{
	int		y;

	y = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * i + 1)))
		exit_error();
	while (y < i)
	{
		arr[y] = ft_strnew(0);
		y++;
	}
	arr[y] = NULL;
	return (arr);
}

int		get_next_move(char **arr, char *name, int i)
{
	int		x;

	x = 0;
	while (arr[i][x])
	{
		if (arr[i][x] == '-' && arr[i][x + 1] != '\0')
		{
			if (ft_strncmp(arr[i] + x + 1, name, ft_strlen(name)) == 0)
			{
				i++;
				x = 0;
			}
		}
		x++;
	}
	ft_strdel(&name);
	return (i);
}

void	check_path(t_lemin *lemin, char **links)
{
	if (ft_strcmp(links[0], lemin->start) == 0 ||
	ft_strcmp(links[1], lemin->start) == 0)
		lemin->check_start = 1;
	if (ft_strcmp(links[0], lemin->end) == 0 ||
	ft_strcmp(links[1], lemin->end) == 0)
		lemin->check_end = 1;
}
