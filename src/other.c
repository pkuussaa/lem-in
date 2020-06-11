/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:34:13 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/11 16:41:58 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		search_name(t_lemin *lemin, char **arr, char *name)
{
	int		y;

	y = 0;
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

char	**init_array(t_lemin *lemin, char *name)
{
	char	**array;
	int		i;

	i = 0;
	if (!(array = (char**)malloc(sizeof(char*) * lemin->rooms + 1)))
		exit_error();
	while (i < lemin->rooms)
	{
		array[i] = ft_strnew(ft_strlen(name) + 1);
		array[i] = ft_strncpy(array[i], name, ft_strlen(name));
		array[i] = ft_strcat(array[i], "-");
		i++;
	}
	array[i] = NULL;
	return (array);
}

int		find_empty(t_lemin *lemin, char **str)
{
	int		y;
	char	*tmp;

	y = 0;
	tmp = ft_strjoin(lemin->start, "-");
	while (str[y])
	{
		if (ft_strcmp(str[y], tmp) == 0)
		{
			ft_strdel(&tmp);
			return (y);
		}
		y++;
	}
	ft_strdel(&tmp);
	return (0);
}
