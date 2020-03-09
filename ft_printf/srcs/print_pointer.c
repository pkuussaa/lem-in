/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:26:33 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 15:59:15 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	uintmax_t	get_variable(t_lst *arr)
{
	uintmax_t i;

	i = (unsigned long)va_arg(arr->args, unsigned long int);
	return ((uintmax_t)i);
}

static	int			get_width(t_lst *arr, long i)
{
	if (arr->period < i)
		return (i + 2);
	return (arr->period + 2);
}

t_lst				*print_pointer(t_lst *arr)
{
	uintmax_t		i;
	char			*str;

	i = get_variable(arr);
	str = itoa_base(i, 16);
	if (arr->period == 0 && i == 0)
		*str = '\0';
	if (arr->flag_arr[4] == '0' && arr->period < 0 && arr->flag_arr[0] != '-')
	{
		arr->period = arr->field_width - 2;
		arr->field_width = 0;
	}
	if (arr->flag_arr[0] == '\0' && arr->field_width > arr->period)
		arr->period > -1 ? print_min_width(arr, get_width(arr,
		(int)ft_strlen(str)), 1) : print_min_width(arr, ft_strlen(str) + 2, 1);
	write(1, "0x", 2);
	print_zeros(arr, ft_strlen(str), 1);
	ft_putstr(str);
	arr->len += (ft_strlen(str) + 2);
	if (arr->flag_arr[0] == '-' && arr->field_width > arr->period)
		arr->period > 11 ? print_min_width(arr, arr->period + 2, 1) :
			print_min_width(arr, ft_strlen(str) + 2, 1);
	free(str);
	return (arr);
}
