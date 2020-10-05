/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_min_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:37:48 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 17:31:02 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*print_min_width(t_lst *arr, int length, intmax_t i)
{
	if (arr->negative == -1 && arr->period != -1)
	{
		arr->negative = -1;
		length++;
	}
	else if (i < 0)
		arr->negative = -1;
	while (arr->field_width > length)
	{
		write(1, " ", 1);
		arr->len++;
		length++;
	}
	return (arr);
}
