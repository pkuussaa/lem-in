/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyrykuussaari <pyrykuussaari@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:41:13 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/03/25 15:15:13 by pyrykuussaa      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		main()
{
	t_graphics	*info;
	t_room		*room;
	char		*line;

	if (!(info = (t_graphics*)malloc(sizeof(t_graphics))))
		exit(EXIT_FAILURE);
	info->mlx = mlx_init();
	info->ptr = mlx_new_window(info->mlx, 1500, 800, "lem-in");
	info->img = mlx_new_image(info->mlx, 1500, 800);
	info->data_addr = mlx_get_data_addr(info->img, &(info->bits_per_pixel),
				&(info->size_line), &(info->endian));
	draw_background(info);
	number_of_ants(info);
	room = parse_rooms(info, room);
	mlx_loop(info->mlx);
	return (0);
}
