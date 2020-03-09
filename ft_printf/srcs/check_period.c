/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_period.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:23:57 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/20 19:10:53 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*check_period(t_lst *arr)
{
	int i;

	i = 0;
	while (arr->copy[arr->i] == '.')
	{
		arr->i++;
		arr->period = 0;
		arr->is_dot = 1;
	}
	if (arr->period == 0)
	{
		while (arr->copy[arr->i] >= '0' && arr->copy[arr->i] <= '9')
		{
			arr->period = arr->period * 10;
			arr->period += (arr->copy[arr->i] - 48);
			arr->i++;
		}
	}
	return (check_modifier_type(arr));
}
