/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:47:26 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 15:58:33 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	uintmax_t	get_type(t_lst *arr)
{
	uintmax_t i;

	i = 0;
	if (ft_strcmp(arr->modifier_arr, "\0") == 0)
		i = (unsigned int)va_arg(arr->args, unsigned int);
	else if (ft_strcmp(arr->modifier_arr, "h") == 0)
		i = (unsigned short)va_arg(arr->args, unsigned int);
	else if (ft_strcmp(arr->modifier_arr, "hh") == 0)
		i = (unsigned char)va_arg(arr->args, unsigned int);
	else if (ft_strcmp(arr->modifier_arr, "l") == 0)
		i = (unsigned long)va_arg(arr->args, unsigned long int);
	else if (ft_strcmp(arr->modifier_arr, "ll") == 0)
		i = (unsigned long long)va_arg(arr->args, unsigned long long int);
	return ((uintmax_t)i);
}

t_lst				*print_u(t_lst *arr)
{
	uintmax_t	i;
	char		*str;
	int			length;

	i = get_type(arr);
	str = itoa_base(i, 10);
	length = ft_strlen(str);
	if (ft_strcmp(str, "0") == 0 && arr->period == 0)
	{
		print_min_width(arr, 0, 1);
		return (arr);
	}
	if (!arr->flag_arr[0] && arr->flag_arr[4] && arr->period == -1)
		arr->period = arr->field_width;
	if (length <= arr->period)
		length = arr->period;
	if (arr->flag_arr[0] == '\0')
		print_min_width(arr, length, 1);
	print_zeros(arr, ft_strlen(str), 1);
	ft_putstr(str);
	arr->len += ft_strlen(str);
	if (arr->flag_arr[0] == '-')
		print_min_width(arr, length, 1);
	free(str);
	return (arr);
}
