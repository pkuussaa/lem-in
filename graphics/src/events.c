/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:40:22 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/09 18:53:14 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		start(int button, int x, int y, void *param)
{
	t_graphics *info;

	info = param;
	if (button == 1 || button == 2)
	{
		scan_paths(info, info->room, info->room);
	}
	return (0);
}
