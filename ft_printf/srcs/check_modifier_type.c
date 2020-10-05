/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_modifier_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:34:35 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/16 18:10:58 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*check_modifier_type(t_lst *arr)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (arr->modifiers[i])
	{
		while (arr->copy[arr->i] == arr->modifiers[i])
		{
			arr->modifier_arr[a] = arr->copy[arr->i];
			if (a < 1)
				a++;
			arr->i++;
		}
		i++;
	}
	return (check_arg_type(arr));
}
