/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:48:17 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 14:12:27 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

double	*handle_link(t_room *room, char **links)
{
	t_room	*tmp;
	t_room	*tmp2;
	double	*arr;

	tmp = find_room(room, links[0]);
	tmp2 = find_room(room, links[1]);
	if (!(arr = (double*)malloc(sizeof(double) * 4)))
		exit(EXIT_FAILURE);
	arr[0] = tmp->x;
	arr[1] = tmp->y;
	arr[2] = tmp2->x;
	arr[3] = tmp2->y;
	free_2d_array(links);
	return (arr);
}

double	*line_draw_values(double *arr)
{
	if (arr[1] < arr[3])
	{
		arr[1] += 20;
		arr[3] -= 20;
	}
	else
	{
		arr[3] += 20;
		arr[1] -= 20;
	}
	return (arr);
}

double	*get_coord(double *arr)
{
	double	x;
	double	y;

	x = (arr[0] - arr[2]) > 0 ? arr[0] - arr[2] : (arr[0] - arr[2]) * -1;
	y = (arr[1] - arr[3]) > 0 ? arr[1] - arr[3] : (arr[1] - arr[3]) * -1;
	if (x >= y)
	{
		if (arr[0] > arr[2])
		{
			arr[2] += 20;
			arr[0] -= 20;
		}
		else
		{
			arr[0] += 20;
			arr[2] -= 20;
		}
	}
	else
		arr = line_draw_values(arr);
	return (arr);
}

void	draw_links(t_graphics *info, t_room *room)
{
	int		i;
	double	*arr;

	i = 0;
	info->color = 0XFFFFFF;
	while (info->links[i])
	{
		arr = handle_link(room, ft_strsplit(info->links[i], '-'));
		arr = get_coord(arr);
		bresenham_algorithm(info, arr);
		i++;
	}
}
