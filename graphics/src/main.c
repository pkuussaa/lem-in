/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:41:13 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/09 19:43:55 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

t_ants	**init_ants(t_graphics *info)
{
	t_ants	**tmp;
	int		i;

	i = 0;
	if (!(tmp = (t_ants **)malloc(sizeof(t_ants *) * info->ants + 1)))
		exit(EXIT_FAILURE);
	while (i < info->ants)
	{
		if (!(tmp[i] = (t_ants *)malloc(sizeof(t_ants))))
			exit(EXIT_FAILURE);
		tmp[i]->name = i + 1;
		tmp[i]->room_name = ft_strdup(info->start);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

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

double		*init_list_int(double x, double y)
{
	double		*list;

	if (!(list = (double*)malloc(sizeof(double) * 2)))
		exit(EXIT_FAILURE);
	list[0] = x;
	list[1] = y;
	return (list);
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
	i += 1;
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
	if (info->stop == 0)
	{
		mlx_clear_window(info->mlx, info->ptr);
		mlx_put_image_to_window(info->mlx, info->ptr, info->img, 0, 0);
		draw_links(info, info->room);
		mlx_string_put(info->mlx, info->ptr, 649, 399, 0X0C87D5, "S C A N N I N G . . .");
		mlx_string_put(info->mlx, info->ptr, 650, 400, 0XC4CC19, "S C A N N I N G . . .");
		if (scan_paths(info, info->room, info->room) == 1)
		{
			info->stop = 1;
			draw_circles(info, info->room, 20);
		}
	}
	if (info->stop == 1)
	{
		mlx_clear_window(info->mlx, info->ptr);
		mlx_put_image_to_window(info->mlx, info->ptr, info->img, 0, 0);
		draw_links(info, info->room);
		if (loop_and_draw(info, info->paths, info->size[y]) == 1 && y < info->loop)
			y++;
		if (y == info->loop)
			info->stop = 2;
	}
	return (0);
}

void	init_result_array(t_graphics *info)
{
	int		i;
	int		y;
	int		x;

	y = 0;
	while (info->result[y])
		y++;
	info->loop = y;
	if (!(info->indexes = (int**)malloc(sizeof(int*) * y)))
			exit(EXIT_FAILURE);
	if (!(info->paths = (double****)malloc(sizeof(double***) * y)))
			exit(EXIT_FAILURE);
	if (!(info->size = (int*)malloc(sizeof(int) * y)))
		exit(EXIT_FAILURE);
	y = 0;
	while (info->result[y])
	{
		i = 0;
		x = 0;
		while (info->result[y][i])
			i++;
		if (!(info->paths[y] = (double***)malloc(sizeof(double**) * i)))
			exit(EXIT_FAILURE);
		info->size[y] = i;
		if (!(info->indexes[y] = (int*)malloc(sizeof(int) * i)))
			exit(EXIT_FAILURE);
		info->y = y;
		while (x < i)
		{
			info->index = x;
			info->paths[y][x] = moving_algorithm(info, info->ant_moves[y][x]);
			x++;
		}
		y++;
	}
}

int		main()
{
	t_graphics	*info;
	t_room		*room;
	t_ants		**ants;
	char		*line;

	if (!(info = (t_graphics*)malloc(sizeof(t_graphics))))
		exit(EXIT_FAILURE);
	info->mlx = mlx_init();
	info->ptr = mlx_new_window(info->mlx, 1500, 800, "lem-in");
	info->img = mlx_new_image(info->mlx, 1500, 800);
	info->data_addr = mlx_get_data_addr(info->img, &(info->bits_per_pixel),
				&(info->size_line), &(info->endian));
	info->stop = -1;
	info->index = 0;
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
	init_result_array(info);
	mlx_loop_hook(info->mlx, handle_loop, info);
	mlx_loop(info->mlx);
	return (0);
}
