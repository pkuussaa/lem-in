/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 12:13:47 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 15:46:02 by pkuussaa         ###   ########.fr       */
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

static	int			is_hash(t_lst *arr, char *str)
{
	if (ft_strcmp(str, "0") == 0 && arr->period == -1)
		return (0);
	else
		return (arr->flag_arr[3] == '#');
	return (0);
}

static	t_lst		*input_hash(t_lst *arr, char *str)
{
	write(1, "0", 1);
	arr->len++;
	if (ft_strcmp(str, "0") != 0)
		arr->zeros_printed++;
	return (arr);
}

static t_lst		*input_str(t_lst *arr, char *str)
{
	ft_putstr(str);
	arr->len += ft_strlen(str);
	return (arr);
}

t_lst				*print_octal(t_lst *arr)
{
	uintmax_t	i;
	char		*str;

	i = get_type(arr);
	str = itoa_base(i, 8);
	if (arr->flag_arr[4] == '0' && arr->flag_arr[0] != '-' && arr->period < 0)
		arr->period = arr->field_width > 0 ? arr->field_width : -1;
	if (arr->flag_arr[0] == '\0')
		arr->period > (long)ft_strlen(str) || (arr->period == 0 && ft_strcmp(
		str, "0") == 0) ? print_min_width(arr, arr->period + is_hash(arr,
		str), 1) : print_min_width(arr, ft_strlen(str) + is_hash(arr, str), 1);
	if (arr->flag_arr[3] == '#')
		input_hash(arr, str);
	print_zeros(arr, ft_strlen(str) + arr->zeros_printed, 1);
	if (ft_strcmp(str, "0") == 0 && (arr->period == 0 ||
		arr->flag_arr[3] == '#'))
		arr->period = 0;
	else
		input_str(arr, str);
	if (arr->flag_arr[0] == '-')
		arr->period == 0 && ft_strcmp(str, "0") == 0 &&
			arr->flag_arr[3] == '\0' ? print_min_width(arr, arr->period, 1) :
			print_min_width(arr, ft_strlen(str) + arr->zeros_printed, 1);
	free(str);
	return (arr);
}
