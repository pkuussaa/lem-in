/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:11:48 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 15:47:00 by pkuussaa         ###   ########.fr       */
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

double	*init_list_int(double x, double y)
{
	double		*list;

	if (!(list = (double*)malloc(sizeof(double) * 2)))
		exit(EXIT_FAILURE);
	list[0] = x;
	list[1] = y;
	return (list);
}

void	init_info(t_graphics *info)
{
	info->mlx = mlx_init();
	info->ptr = mlx_new_window(info->mlx, 1500, 800, "lem-in");
	info->img = mlx_new_image(info->mlx, 1500, 800);
	info->img2 = mlx_new_image(info->mlx, 750, 400);
	info->data_addr = mlx_get_data_addr(info->img, &(info->bits_per_pixel),
				&(info->size_line), &(info->endian));
	info->data_addr2 = mlx_get_data_addr(info->img2, &(info->bits_per_pixel2),
				&(info->size_line2), &(info->endian2));
	info->stop = -1;
	info->index = 0;
	info->speed = 1;
	info->check = 0;
	info->i = 0;
}

void	allocate_result_lists(t_graphics *info, int y, int check)
{
	if (check == -1)
	{
		if (!(info->indexes = (int**)malloc(sizeof(int*) * y)))
			exit(EXIT_FAILURE);
		if (!(info->paths = (double****)malloc(sizeof(double***) * y)))
			exit(EXIT_FAILURE);
		if (!(info->size = (int*)malloc(sizeof(int) * y)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!(info->paths[y] = (double***)malloc(sizeof(double**) * check)))
			exit(EXIT_FAILURE);
		if (!(info->indexes[y] = (int*)malloc(sizeof(int) * check)))
			exit(EXIT_FAILURE);
	}
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
	allocate_result_lists(info, y, -1);
	y = -1;
	while (info->result[++y])
	{
		i = 0;
		x = -1;
		while (info->result[y][i])
			i++;
		allocate_result_lists(info, y, i);
		info->size[y] = i;
		info->y = y;
		while (++x < i)
		{
			info->index = x;
			info->paths[y][x] = moving_algorithm(info, info->ant_moves[y][x]);
		}
	}
}
