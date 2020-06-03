/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:41:13 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/03 16:32:12 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

t_room	*find_room(t_room *room, char *name)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

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
	//draw_background(info);
	number_of_ants(info);
	room = parse_rooms(info, room);
	result_rooms(info, room);
	draw_circles(info, room);
	mlx_loop(info->mlx);
	return (0);
}
