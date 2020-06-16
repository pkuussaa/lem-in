/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing_algorithm.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:20:59 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 13:11:16 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

double	*init_list(double start_x, double start_y, double end_x,
													double end_y)
{
	double *arr;

	if (!(arr = (double *)malloc(sizeof(double) * 4)))
		return (0);
	arr[0] = start_x;
	arr[1] = start_y;
	arr[2] = end_x;
	arr[3] = end_y;
	return (arr);
}

void	line_high(t_graphics *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = x < 0 ? -1 : 1;
	if (x < 0)
		x = -x;
	d = 2 * x - y;
	while (arr[1] < arr[3])
	{
		mlx_pixel_put(info->mlx, info->ptr, arr[0],
		arr[1], info->color);
		if (d > 0)
		{
			arr[0] += check;
			d -= 2 * y;
		}
		d += 2 * x;
		arr[1]++;
	}
	free(arr);
}

void	line_low(t_graphics *info, double *arr)
{
	double	x;
	double	y;
	int		check;
	double	d;

	x = arr[2] - arr[0];
	y = arr[3] - arr[1];
	check = y < 0 ? -1 : 1;
	if (y < 0)
		y = -y;
	d = (2 * y) - x;
	while (arr[0] < arr[2])
	{
		mlx_pixel_put(info->mlx, info->ptr, arr[0],
		arr[1], info->color);
		if (d > 0)
		{
			arr[1] += check;
			d -= 2 * x;
		}
		d += 2 * y;
		arr[0]++;
	}
	free(arr);
}

void	bresenham_algorithm(t_graphics *info, double *arr)
{
	double	y_abs;
	double	x_abs;

	y_abs = arr[3] - arr[1] > 0 ? arr[3] - arr[1] : (arr[3] - arr[1]) * -1;
	x_abs = arr[2] - arr[0] > 0 ? arr[2] - arr[0] : -(arr[2] - arr[0]);
	if (y_abs < x_abs)
	{
		if (arr[0] > arr[2])
			line_low(info, init_list(arr[2], arr[3], arr[0], arr[1]));
		else
			line_low(info, init_list(arr[0], arr[1], arr[2], arr[3]));
	}
	else
	{
		if (arr[1] > arr[3])
			line_high(info, init_list(arr[2], arr[3], arr[0], arr[1]));
		else
			line_high(info, init_list(arr[0], arr[1], arr[2], arr[3]));
	}
	free(arr);
}
