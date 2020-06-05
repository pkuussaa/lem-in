/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:48:17 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/05 15:58:02 by pkuussaa         ###   ########.fr       */
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

double	*handle_link(t_room *room, char **links)
{
	t_room	*tmp;
	t_room	*tmp2;
	double	*arr;

	tmp = find_room(room, links[0]);
	tmp2 = find_room(room, links[1]);
	if (!(arr = (double*)malloc(sizeof(double) * 4)))
		exit(EXIT_FAILURE);
	arr[0] = tmp->x;
	arr[1] = tmp->y;
	arr[2] = tmp2->x;
	arr[3] = tmp2->y;
	return (arr);
}

double	*get_draw_coordinates(double *arr)
{
	double	x;
	double	y;

	x = (arr[0] - arr[2]) > 0 ? arr[0] - arr[2] : (arr[0] - arr[2]) * -1;
	y = (arr[1] - arr[3]) > 0 ? arr[1] - arr[3] : (arr[1] - arr[3]) * -1;
	if (x >= y)
	{
		if (arr[0] > arr[2])
		{
			//arr[1] = arr[1] + 10;
			//arr[3] = arr[3] + 10;
			arr[2] += 20;
			arr[0] -= 20;
		}
		else
		{
			//arr[1] += 20;
			arr[0] += 20;
			//arr[3] += 20;
			arr[2] -= 20;
		}

	}
	else
	{
		if (arr[1] < arr[3])
		{
			//arr[0] += 35;
			arr[1] += 20;
			//arr[2] += 35;
			arr[3] -= 20;
		}
		else
		{
			//arr[0] += 35;
			//arr[2] += 35;
			arr[3] += 20;
			arr[1] -= 20;
		}
	}
	return (arr);
}

void	draw_links(t_graphics *info, t_room *room)
{
	int		i;
	double	*arr;

	i = 0;
	info->color = 0XFFFFFF;
	while (info->links[i])
	{
		arr = handle_link(room, ft_strsplit(info->links[i], '-'));
		arr = get_draw_coordinates(arr);
		bresenham_algorithm(info, arr);
		i++;
	}
}
