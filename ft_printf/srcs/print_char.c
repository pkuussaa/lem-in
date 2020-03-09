/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:36:36 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 17:33:26 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*print_char(t_lst *arr)
{
	char c;

	c = (char)va_arg(arr->args, int);
	if (arr->field_width > 0 && arr->flag_arr[0] == '\0')
	{
		print_min_width(arr, 1, 0);
		write(1, &c, 1);
		arr->len++;
	}
	else if (arr->field_width > 0 && arr->flag_arr[0] == '-')
	{
		write(1, &c, 1);
		print_min_width(arr, 1, 0);
		arr->len++;
	}
	else
	{
		write(1, &c, 1);
		arr->len++;
	}
	return (arr);
}
