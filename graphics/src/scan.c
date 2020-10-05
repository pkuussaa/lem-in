/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 12:07:16 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/15 16:39:16 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	put_scan_px(t_graphics *info, t_room *room, int x, int y)
{
	int		c;

	c = 0X39B1B6;
	if (info->check == 3)
	{
		mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y + y, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y + y - 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y + y - 2, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y - y, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y - y + 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y - y + 2, c);
	}
	if (info->check == 2)
	{
		mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y + y, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y + y - 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - x, room->y + y - 2, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y - y, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y - y + 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + x, room->y - y + 2, c);
	}
}

void	put_scan_px2(t_graphics *info, t_room *room, int x, int y)
{
	int		c;

	c = 0X39B1B6;
	if (info->check == 0)
	{
		mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y + x, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y + x - 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y + x - 2, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y - x, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y - x + 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y - x + 2, c);
	}
	if (info->check == 1)
	{
		mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y + x, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y + x - 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x - y, room->y + x - 2, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y - x, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y - x + 1, c);
		mlx_pixel_put(info->mlx, info->ptr, room->x + y, room->y - x + 2, c);
	}
	put_scan_px(info, room, x, y);
}

void	scan_delay(t_graphics *info, int x)
{
	while (x < 75000000)
		x++;
	info->check++;
	info->i++;
	if (info->check == 4)
		info->check = 0;
}

int		scan_paths(t_graphics *info, t_room *room, t_room *tmp)
{
	int			arr[4];

	arr[2] = 22;
	arr[0] = 0;
	arr[1] = arr[2];
	arr[3] = 3 - 2 * arr[2];
	while (arr[1] >= arr[0])
	{
		arr[0]++;
		if (arr[3] > 0)
		{
			arr[1]--;
			arr[3] = arr[3] + 4 * (arr[0] - arr[1]) + 10;
		}
		else
			arr[3] = arr[3] + 4 * arr[0] + 6;
		put_scan_px2(info, room, arr[0], arr[1]);
	}
	if (room->next)
		scan_paths(info, room->next, tmp);
	else
		scan_delay(info, 0);
	if (info->i == 50)
		return (1);
	return (0);
}
