/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:59:47 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/20 18:25:00 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*print_zeros(t_lst *arr, int length, intmax_t i)
{
	if (length < arr->period && i < 0)
	{
		arr->negative = -1;
		length--;
	}
	if (arr->period != -1 && (arr->arg_type == 'i' || arr->arg_type == 'd'
		|| arr->arg_type == 'p' || arr->arg_type == 'o' || arr->arg_type == 'u'
		|| arr->arg_type == 'x' || arr->arg_type == 'X'))
		while (arr->period > length)
		{
			write(1, "0", 1);
			arr->zeros_printed++;
			arr->len++;
			length++;
		}
	else if (arr->arg_type != 'p' && arr->arg_type != 'o' && arr->arg_type
			!= 'u' && arr->arg_type != 'x' && arr->arg_type != 'X')
		while (arr->field_width > length)
		{
			write(1, "0", 1);
			arr->zeros_printed++;
			arr->len++;
			length++;
		}
	return (arr);
}
