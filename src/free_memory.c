/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:35:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/11 13:23:54 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_2d_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

void	free_items(char **arr, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}
