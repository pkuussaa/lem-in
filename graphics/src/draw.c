/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:01:20 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/09 19:14:35 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	display_circle(t_graphics *info, t_room *room, int x, int y)
{
	int		*image;
	int color;
	int offset;

	image = (int*)(info->data_addr);
	if (info->stop == 1)
		color = room->result == 1 ? 0X23CD21 : 0XFFFFFF;
	else
		color = 0XFFFFFF;
	color = ft_strcmp(room->name, info->start) == 0 ? 0XCD1FBA: color;
	color = ft_strcmp(room->name, info->end) == 0 ? 0XC4CC19: color;
	offset = room->x + (room->y * 1500);
	image[(offset - (y * 1500)) + x] = color;
	image[(offset - (y * 1500)) - x] = color;
	image[(offset + (y * 1500)) + x] = color;
	image[(offset + (y * 1500)) - x] = color;
	image[(offset - (x * 1500)) + y] = color;
	image[(offset - (x * 1500)) - y] = color;
	image[(offset + (x * 1500)) + y] = color;
	image[(offset + (x * 1500)) - y] = color;
}

void	circle_drawing_algorithm(int radius, t_graphics *info, t_room *room, int check)
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
		display_circle(info, room, x, y);
		if (check == 0)
		{
			display_circle(info, room, x, y - 1);
			display_circle(info, room, x, y - 2);
		}
	}
}

void	draw_circles(t_graphics *info, t_room *room, int radius)
{
	display_circle(info, room, 0, radius);
	if (ft_strcmp(room->name, info->start) == 0 || ft_strcmp(room->name, info->end) == 0)
		while (radius > 0)
		{
			display_circle(info, room, 0, radius);
			circle_drawing_algorithm(radius, info, room, 1);
			radius--;
		}
	else
		circle_drawing_algorithm(radius, info, room, 0);
	if (room->next)
		draw_circles(info, room->next, 20);
	else
		mlx_put_image_to_window(info->mlx, info->ptr, info->img, 0, 0);
}

/*void	draw_box(t_graphics *info, t_room *room)
{
	int		*image;
	int		i;
	int		counter;

	ft_printf("%d %d\n", room->x, room->y);
	i = room->x + (room->y * 1500);
	counter = 0;
	image = (int*)(info->data_addr);
	while (counter < 70)
	{
		image[i] = 0XFFFFFF;
		image[i + (1500 * 40)] = 0XFFFFFF;
		counter++;
		i++;
	}
	counter = 0;
	while (counter < 40)
	{
		image[i] = 0XFFFFFF;
		image[i - 70] = 0XFFFFFF;
		counter++;
		i += 1500;
	}
	if (room->next)
		draw_box(info, room->next);
	else
		mlx_put_image_to_window(info->mlx, info->ptr, info->img, 0, 0);
}*/

void	draw_background(t_graphics *info)
{
	int *image;
	int i;
	int counter;
	int delim;
	int range[4];

	info->color = 0X39140C;
	ft_bzero(info->data_addr, 1500 * 800 * (info->bits_per_pixel / 8));
	image = (int*)(info->data_addr);
	i = 0;
	counter = 25;
	delim = 0;
	range[0] = 0;
	range[1] = 30000;
	range[2] = 30000;
	range[3] = 60000;
	while (i < 1500 * 800)
	{
		if (i >= range[0] && i <= range[1])
		{
			if (i % 1500 == 0)
			{
				delim = 0;
				counter = 25;
			}
			image[i] = i % 1500 > delim && i % 1500 < counter ? 0X422924 : info->color;
			if (i % 1500 > counter)
			{
				delim = counter + 25;
				counter = counter + 50;
			}
		}
		else if (i > range[1])
		{
			range[0]  += 60000;
			range[1] += 60000;
		}
		if (i >= range[2] && i <= range[3])
		{
			if (i % 1500 == 0)
			{
				delim = 25;
				counter = 50;
			}
			image[i] = i % 1500 > delim && i % 1500 < counter ? 0X43241E : info->color;
			if (i % 1500 > counter)
			{
				delim = counter + 25;
				counter = counter + 50;
			}
		}
		else if (i > range[2])
		{
			range[2] += 60000;
			range[3] += 60000;
		}
		i++;
	}
}
