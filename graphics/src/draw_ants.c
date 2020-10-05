/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:58:45 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 15:52:29 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	display_ant(double *list, int x, int y, t_graphics *info)
{
	mlx_pixel_put(info->mlx, info->ptr, list[0] + x, list[1] + y, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->ptr, list[0] - x, list[1] + y, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->ptr, list[0] + x, list[1] - y, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->ptr, list[0] - x, list[1] - y, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->ptr, list[0] + y, list[1] + x, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->ptr, list[0] - y, list[1] + x, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->ptr, list[0] + y, list[1] - x, 0XFFFFFF);
	mlx_pixel_put(info->mlx, info->ptr, list[0] - y, list[1] - x, 0XFFFFFF);
}

void	ant_drawing_algorithm(double *list, int radius, t_graphics *info)
{
	int		x;
	int		y;
	int		dp;

	x = 0;
	y = radius;
	dp = 3 - 2 * radius;
	while (y >= x)
	{
		x++;
		if (dp > 0)
		{
			y--;
			dp = dp + 4 * (x - y) + 10;
		}
		else
			dp = dp + 4 * x + 6;
		display_ant(list, x, y, info);
	}
}

void	draw_ant(t_graphics *info, double *list)
{
	int radius;

	radius = 5;
	if (list[0] == 0 || list[1] == 0)
	{
		free(list);
		return ;
	}
	display_ant(list, 0, radius, info);
	while (radius > 0)
	{
		display_ant(list, 0, radius, info);
		ant_drawing_algorithm(list, radius, info);
		radius--;
	}
	free(list);
}
