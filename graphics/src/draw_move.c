/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 12:42:48 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/09 17:48:31 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		count_alloc2(t_graphics *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;
	int		i;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = x < 0 ? -1 : 1;
	if (x < 0)
		x = -x;
	d = 2 * x - y;
	i = 0;
	while (arr[1] < arr[3])
	{
		if (d > 0)
		{
			arr[0] += check;
			d -= 2 * y;
		}
		d += 2 * x;
		arr[1]++;
		i++;
	}
	info->indexes[info->y][info->index] = i;
	return (i);
}

double	**line_high1(t_graphics *info, double *arr, int j, int checker)
{
	double	x;
	double	y;
	int		check;
	double	d;
	double	**list;
	int		i;

	if (!(list = (double**)malloc(sizeof(double*) * 2)))
		exit(EXIT_FAILURE);
	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = x < 0 ? -1 : 1;
	if (x < 0)
		x = -x;
	d = 2 * x - y;
	if (!(list[0] = (double*)malloc(sizeof(double) * j)))
		exit(EXIT_FAILURE);
	if (!(list[1] = (double*)malloc(sizeof(double) * j)))
		exit(EXIT_FAILURE);
	i = checker == 1 ? j : 0;
	while (arr[1] < arr[3])
	{
		list[0][i] = arr[0];
		list[1][i] = arr[1];
		if (d > 0)
		{
			arr[0] += check;
			d -= 2 * y;
		}
		d += 2 * x;
		arr[1]++;
		i = checker == 1 ? i - 1 : i + 1;
	}
	free(arr);
	return (list);
}

int		count_alloc(t_graphics *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;
	int		i;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = y < 0 ? -1 : 1;
	if (y < 0)
		y = -y;
	d = (2 * y) - x;
	i = 0;
	while (arr[0] < arr[2])
	{
		if (d > 0)
		{
			arr[1] += check;
			d -= 2 * x;
		}
		d += 2 * y;
		arr[0]++;
		i++;
	}
	info->indexes[info->y][info->index] = i;
	return (i);
}

double	**line_low1(t_graphics *info, double *arr, int j, int checker)
{
	double	x;
	double	y;
	int		check;
	double	d;
	double	**list;
	int		i;

	if (!(list = (double**)malloc(sizeof(double*) * 2)))
		exit(EXIT_FAILURE);
	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = y < 0 ? -1 : 1;
	if (y < 0)
		y = -y;
	d = (2 * y) - x;
	if (!(list[0] = (double*)malloc(sizeof(double) * j)))
		exit(EXIT_FAILURE);
	if (!(list[1] = (double*)malloc(sizeof(double) * j)))
		exit(EXIT_FAILURE);
	i = checker == 1 ? j : 0;
	while (arr[0] < arr[2])
	{
		list[0][i] = arr[0];
		list[1][i] = arr[1];
		if (d > 0)
		{
			arr[1] += check;
			d -= 2 * x;
		}
		d += 2 * y;
		arr[0]++;
		i = checker == 1 ? i - 1 : i + 1;
	}
	free(arr);
	return (list);
}

double	**moving_algorithm(t_graphics *info, double *arr)
{
	double	y_abs;
	double	x_abs;

	y_abs = arr[3] - arr[1] > 0 ? arr[3] - arr[1] : (arr[3] - arr[1]) * -1;
	x_abs = arr[2] - arr[0] > 0 ? arr[2] - arr[0] : -(arr[2] - arr[0]);
	if (y_abs < x_abs)
	{
		if (arr[0] > arr[2])
			return (line_low1(info, init_list(arr[2], arr[3], arr[0], arr[1]), count_alloc(info, init_list(arr[2], arr[3], arr[0], arr[1])), 1));
		else
			return (line_low1(info, init_list(arr[0], arr[1], arr[2], arr[3]), count_alloc(info, init_list(arr[0], arr[1], arr[2], arr[3])), 0));
	}
	else
	{
		if (arr[1] > arr[3])
			return (line_high1(info, init_list(arr[2], arr[3], arr[0], arr[1]), count_alloc2(info, init_list(arr[2], arr[3], arr[0], arr[1])), 1));
		else
			return (line_high1(info, init_list(arr[0], arr[1], arr[2], arr[3]), count_alloc2(info, init_list(arr[0], arr[1], arr[2], arr[3])), 0));
	}
}
