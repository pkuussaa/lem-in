/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:07:16 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/03 15:55:03 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	scan_paths(t_graphics *info, t_room *room, t_room *tmp, int check, int index)
{
	int		radius;
	int		x;
	int		y;
	int		dp;

	radius = 22;
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
		if (check == 0)
		{
			mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y + y, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y + y - 1, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y - y, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y - y + 1, 0X39B1B6);
		}
		if (check == 1)
		{
			mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y + y, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y + y - 1, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y - y, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y - y + 1, 0X39B1B6);
		}
		if (check == 2)
		{
			mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y + x, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y + x - 1, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y - x, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y - x + 1, 0X39B1B6);
		}
		if (check == 3)
		{
			mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y + x, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y + x - 1, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y - x, 0X39B1B6);
			mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y - x + 1, 0X39B1B6);
		}
	}
	if (room->next)
		scan_paths(info, room->next, tmp, check, index);
	else if (index < 20)
	{
		if (check == 3)
			check = 0;
		mlx_clear_window(info->mlx, info->ptr);
		mlx_put_image_to_window(info->mlx, info->ptr, info->img, 0, 0);
		scan_paths(info, tmp, tmp, check + 1, index + 1);
	}
}
