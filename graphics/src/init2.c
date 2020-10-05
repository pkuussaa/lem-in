/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:07:15 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/25 15:27:39 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

double	**allocate_2d_int(double **list, int j)
{
	if (!(list = (double**)malloc(sizeof(double*) * 2)))
		exit(EXIT_FAILURE);
	if (!(list[0] = (double*)malloc(sizeof(double) * j)))
		exit(EXIT_FAILURE);
	if (!(list[1] = (double*)malloc(sizeof(double) * j)))
		exit(EXIT_FAILURE);
	return (list);
}

double	*init_arr(t_graphics *info, double *xy, double *arr, int check)
{
	if (!(xy = (double*)malloc(sizeof(double) * 3)))
		exit(EXIT_FAILURE);
	xy[0] = arr[2] - arr[0];
	xy[1] = arr[3] - arr[1];
	if (check == 1)
	{
		info->checker = xy[1] < 0 ? -1 : 1;
		xy[1] = xy[1] < 0 ? -xy[1] : xy[1];
		xy[2] = (2 * xy[1]) - xy[0];
	}
	else
	{
		info->checker = xy[0] < 0 ? -1 : 1;
		xy[0] = xy[0] < 0 ? -xy[0] : xy[0];
		xy[2] = 2 * xy[0] - xy[1];
	}
	return (xy);
}

char	**init_char(char *str, char *str2)
{
	char	**arr;

	if (!(arr = (char**)malloc(sizeof(char*) * 3)))
		exit(EXIT_FAILURE);
	arr[0] = ft_strdup(str);
	arr[1] = ft_strdup(str2);
	ft_strdel(&str2);
	ft_strdel(&str);
	arr[2] = NULL;
	return (arr);
}

void	init_result_list(t_graphics *info, char **arr)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (arr[size])
		size++;
	if (!(info->result = (char***)malloc(sizeof(char**) * size + 1)))
		exit(EXIT_FAILURE);
	if (!(info->ant_moves = (double***)malloc(sizeof(double**) * size)))
		exit(EXIT_FAILURE);
	while (arr[i])
	{
		info->result[i] = ft_strsplit(arr[i], ' ');
		i++;
	}
	free_2d_array(arr);
	info->result[i] = NULL;
}
