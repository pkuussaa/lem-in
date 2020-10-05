/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:40:22 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/15 15:15:37 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		mouse_press(int button, int x, int y, void *param)
{
	t_graphics *info;

	info = param;
	if (button == 1 && info->stop == -1)
	{
		if (x >= 525 && x <= 665 && y >= 400 && y <= 480)
			info->stop = 0;
		if (x >= 825 && x <= 965 && y >= 400 && y <= 480)
			exit(EXIT_SUCCESS);
	}
	return (0);
}

int		key_press(int keycode, void *param)
{
	t_graphics	*info;

	info = param;
	if (keycode == 53)
		exit(0);
	if (keycode == 27 && info->speed > 1)
		info->speed--;
	if (keycode == 24 && info->speed < 10)
		info->speed++;
	return (0);
}

void	scan(t_graphics *info)
{
	mlx_clear_window(info->mlx, info->ptr);
	mlx_put_image_to_window(info->mlx, info->ptr, info->img, 0, 0);
	draw_links(info, info->room);
	mlx_string_put(info->mlx, info->ptr, 649, 399, 0X0C87D5,
	"S C A N N I N G . . .");
	mlx_string_put(info->mlx, info->ptr, 650, 400, 0XC4CC19,
	"S C A N N I N G . . .");
	if (scan_paths(info, info->room, info->room) == 1)
	{
		info->stop = 1;
		draw_circles(info, info->room, 20);
	}
}

void	main_loop(t_graphics *info)
{
	mlx_clear_window(info->mlx, info->ptr);
	mlx_put_image_to_window(info->mlx, info->ptr, info->img, 0, 0);
	mlx_string_put(info->mlx, info->ptr, 1300, 10, 0X0C87D5,
	"Add speed: < + >");
	mlx_string_put(info->mlx, info->ptr, 1300, 30, 0X0C87D5,
	"Lower speed: < - >");
	draw_links(info, info->room);
}
