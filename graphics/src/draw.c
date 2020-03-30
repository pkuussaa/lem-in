/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyrykuussaari <pyrykuussaari@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:01:20 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/03/30 13:22:07 by pyrykuussaa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	draw_box(t_graphics *info, t_room *room)
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
}

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
