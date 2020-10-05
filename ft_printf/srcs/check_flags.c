/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:47:38 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/16 18:09:49 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*check_flags(t_lst *arr)
{
	int i;

	i = 0;
	while (arr->flags[i] != '\0')
	{
		while (arr->flags[i] == arr->copy[arr->i])
		{
			while (arr->copy[arr->i] == '-' && arr->i++)
				arr->flag_arr[0] = '-';
			while (arr->copy[arr->i] == ' ' && arr->i++)
				arr->flag_arr[1] = ' ';
			while (arr->copy[arr->i] == '+' && arr->i++)
				arr->flag_arr[2] = '+';
			while (arr->copy[arr->i] == '#' && arr->i++)
				arr->flag_arr[3] = '#';
			while (arr->copy[arr->i] == '0' && arr->i++)
				arr->flag_arr[4] = '0';
			i = 0;
		}
		i++;
	}
	return (check_width(arr));
}
