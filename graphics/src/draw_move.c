/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 12:42:48 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 16:09:32 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		count_alloc2(t_graphics *info, double *arr)
{
	double	xy[2];
	int		check;
	double	d;
	int		i;

	xy[0] = arr[2] - arr[0];
	xy[1] = arr[3] - arr[1];
	check = xy[0] < 0 ? -1 : 1;
	xy[0] = xy[0] < 0 ? -xy[0] : xy[0];
	d = 2 * xy[0] - xy[1];
	i = 0;
	while (arr[1] < arr[3])
	{
		if (d > 0)
		{
			arr[0] += check;
			d -= 2 * xy[1];
		}
		d += 2 * xy[0];
		arr[1]++;
		i++;
	}
	info->indexes[info->y][info->index] = i;
	free(arr);
	return (i);
}

double	**line_high1(t_graphics *info, double *arr, int j, int checker)
{
	int		check;
	double	*xy;
	double	**list;
	int		i;

	list = allocate_2d_int(list, j);
	xy = init_arr(info, xy, arr, 2);
	i = checker == 1 ? j : 0;
	while (arr[1] < arr[3])
	{
		list[0][i] = arr[0];
		list[1][i] = arr[1];
		if (xy[2] > 0)
		{
			arr[0] += info->checker;
			xy[2] -= 2 * xy[1];
		}
		xy[2] += 2 * xy[0];
		arr[1]++;
		i = checker == 1 ? i - 1 : i + 1;
	}
	free(arr);
	free(xy);
	return (list);
}

int		count_alloc(t_graphics *info, double *arr)
{
	double	xy[2];
	int		check;
	double	d;
	int		i;

	xy[0] = arr[2] - arr[0];
	xy[1] = arr[3] - arr[1];
	check = xy[1] < 0 ? -1 : 1;
	xy[1] = xy[1] < 0 ? -xy[1] : xy[1];
	d = (2 * xy[1]) - xy[0];
	i = 0;
	while (arr[0] < arr[2])
	{
		if (d > 0)
		{
			arr[1] += check;
			d -= 2 * xy[0];
		}
		d += 2 * xy[1];
		arr[0]++;
		i++;
	}
	info->indexes[info->y][info->index] = i;
	free(arr);
	return (i);
}

double	**line_low1(t_graphics *info, double *arr, int j, int checker)
{
	double	*xy;
	double	**list;
	int		i;

	list = allocate_2d_int(list, j);
	xy = init_arr(info, xy, arr, 1);
	i = checker == 1 ? j : 0;
	while (arr[0] < arr[2])
	{
		list[0][i] = arr[0];
		list[1][i] = arr[1];
		if (xy[2] > 0)
		{
			arr[1] += info->checker;
			xy[2] -= 2 * xy[0];
		}
		xy[2] += 2 * xy[1];
		arr[0]++;
		i = checker == 1 ? i - 1 : i + 1;
	}
	free(xy);
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
			return (line_low1(info, init_list(arr[2], arr[3], arr[0], arr[1]),
			count_alloc(info, init_list(arr[2], arr[3], arr[0], arr[1])), 1));
		else
			return (line_low1(info, init_list(arr[0], arr[1], arr[2], arr[3]),
			count_alloc(info, init_list(arr[0], arr[1], arr[2], arr[3])), 0));
	}
	else
	{
		if (arr[1] > arr[3])
			return (line_high1(info, init_list(arr[2], arr[3], arr[0], arr[1]),
			count_alloc2(info, init_list(arr[2], arr[3], arr[0], arr[1])), 1));
		else
			return (line_high1(info, init_list(arr[0], arr[1], arr[2], arr[3]),
			count_alloc2(info, init_list(arr[0], arr[1], arr[2], arr[3])), 0));
	}
}
