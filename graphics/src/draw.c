/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:01:20 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/15 15:17:38 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	display_circle(t_graphics *info, t_room *room, int x, int y)
{
	int	*image;
	int	color;
	int	offset;

	image = (int*)(info->data_addr);
	if (info->stop == 1)
		color = room->result == 1 ? 0X23CD21 : 0XFFFFFF;
	else
		color = 0XFFFFFF;
	color = ft_strcmp(room->name, info->start) == 0 ? 0XCD1FBA : color;
	color = ft_strcmp(room->name, info->end) == 0 ? 0XC4CC19 : color;
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

void	circle_drawing_algorithm(int radius,
		t_graphics *info, t_room *room, int check)
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
	if (ft_strcmp(room->name, info->start) == 0 ||
	ft_strcmp(room->name, info->end) == 0)
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

void	draw_box(t_graphics *info, int x, int y, int check)
{
	int		*image;
	int		i;
	int		counter;

	i = x + (750 * y);
	counter = 0;
	image = (int*)(info->data_addr2);
	while (counter < 140)
	{
		image[i] = 0XFFFFFF;
		image[i + (750 * 80)] = 0XFFFFFF;
		counter++;
		i++;
	}
	counter = -1;
	while (++counter < 80)
	{
		image[i] = 0XFFFFFF;
		image[i - 140] = 0XFFFFFF;
		i += 750;
	}
	if (check == 0)
		draw_box(info, 450, 200, 1);
	else
		mlx_put_image_to_window(info->mlx, info->ptr, info->img2, 375, 200);
}

void	draw_start_box(t_graphics *info)
{
	int	*image;
	int	i;

	ft_bzero(info->data_addr2, 750 * 400 * (info->bits_per_pixel2 / 8));
	image = (int*)(info->data_addr2);
	i = 0;
	while (i < 750 * 400)
	{
		if (i <= 7500 || i % 750 >= 740 || i % 750 <= 10 || i >= 292500)
			image[i] = 0X3E3434;
		else
			image[i] = 0X1E2123;
		i++;
	}
	draw_box(info, 150, 200, 0);
	mlx_string_put(info->mlx, info->ptr, 570, 430, 0XFFFFFF, "START");
	mlx_string_put(info->mlx, info->ptr, 875, 430, 0XFFFFFF, "EXIT");
	mlx_string_put(info->mlx, info->ptr, 630, 250, 0XCD1FBA, "L  E  M");
	mlx_string_put(info->mlx, info->ptr, 629, 249, 0XCD1FBA, "L  E  M");
	mlx_string_put(info->mlx, info->ptr, 740, 270, 0X23CD21, "-");
	mlx_string_put(info->mlx, info->ptr, 739, 269, 0X23CD21, "-");
	mlx_string_put(info->mlx, info->ptr, 790, 290, 0XC4CC19, "I  N");
	mlx_string_put(info->mlx, info->ptr, 789, 289, 0XC4CC19, "I  N");
}
