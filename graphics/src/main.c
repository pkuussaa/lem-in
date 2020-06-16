/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:41:13 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/16 17:38:07 by pkuussaa         ###   ########.fr       */
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

int		loop_and_draw(t_graphics *info, double ****arr, int size)
{
	int			y;
	static int	i;
	static int	z;
	int			count;

	y = 0;
	count = 0;
	while (y < size)
	{
		if (i < info->indexes[z][y])
			draw_ant(info, init_list_int(arr[z][y][0][i], arr[z][y][1][i]));
		else
			count++;
		y++;
	}
	if (count == size)
	{
		z++;
		i = 0;
		return (1);
	}
	i += info->speed;
	return (0);
}

int		handle_loop(void *param)
{
	t_graphics	*info;
	static int	y;
	int			i;
	int			x;
	double		***arr;

	info = (t_graphics*)param;
	i = 0;
	mlx_hook(info->ptr, 4, 0, mouse_press, info);
	mlx_hook(info->ptr, 2, 0, key_press, info);
	if (info->stop == 0)
		scan(info);
	if (info->stop == 1)
	{
		main_loop(info);
		if (loop_and_draw(info, info->paths, info->size[y]) == 1
		&& y < info->loop)
			y++;
		if (y == info->loop)
			info->stop = 2;
	}
	return (0);
}

int		main(void)
{
	t_graphics	*info;
	t_room		*room;
	t_ants		**ants;
	char		*line;

	if (!(info = (t_graphics*)malloc(sizeof(t_graphics))))
		exit(EXIT_FAILURE);
	init_info(info);
	number_of_ants(info);
	room = parse_rooms(info, room);
	info->room = room;
	parse_links(info, room);
	result_rooms(info, room);
	ants = init_ants(info);
	info->ant = ants;
	parse_result(info);
	draw_circles(info, room, 20);
	draw_links(info, room);
	move_ants(info, info->ant);
	draw_start_box(info);
	init_result_array(info);
	mlx_loop_hook(info->mlx, handle_loop, info);
	mlx_loop(info->mlx);
	return (0);
}
