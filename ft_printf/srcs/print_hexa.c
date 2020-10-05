/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:51:11 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 16:43:41 by pkuussaa         ###   ########.fr       */
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

static	t_lst		*is_hash(t_lst *arr, char *s)
{
	if (arr->arg_type == 'x' && arr->flag_arr[3] == '#' &&
	ft_strcmp(s, "0") != 0)
	{
		write(1, "0x", 2);
		arr->len += 2;
	}
	else if (arr->arg_type == 'X' && arr->flag_arr[3] == '#' &&
	ft_strcmp(s, "0") != 0)
	{
		write(1, "0X", 2);
		arr->len += 2;
	}
	return (arr);
}

static	t_lst		*check_zero(t_lst *arr)
{
	print_min_width(arr, 0, 1);
	return (arr);
}

static	int			check_length(t_lst *arr, int length)
{
	if (length <= arr->period)
		return (arr->period);
	return (length);
}

t_lst				*print_hexa(t_lst *arr)
{
	uintmax_t	i;
	char		*s;
	int			length;

	i = get_type(arr);
	s = arr->arg_type == 'x' ? itoa_base(i, 16) : itoa_base_capital(i, 16);
	length = ft_strlen(s);
	if (ft_strcmp(s, "0") == 0 && arr->period == 0)
		return (check_zero(arr));
	if (!arr->flag_arr[0] && arr->flag_arr[4] == '0' && arr->period == -1)
		arr->period = arr->field_width;
	length = check_length(arr, length);
	if (arr->flag_arr[0] == '\0')
		arr->flag_arr[3] == '#' && ft_strcmp(s, "0") != 0 ?
		print_min_width(arr, length + 2, 1) : print_min_width(arr, length, 1);
	is_hash(arr, s);
	arr->flag_arr[3] && arr->flag_arr[4] && ft_strcmp(s, "0") != 0 ?
	print_zeros(arr, ft_strlen(s) + 2, 1) : print_zeros(arr, ft_strlen(s), 1);
	ft_putstr(s);
	arr->len += ft_strlen(s);
	if (arr->flag_arr[0] == '-')
		arr->flag_arr[3] == '#' && ft_strcmp(s, "0") != 0 ?
		print_min_width(arr, length + 2, 1) : print_min_width(arr, length, 1);
	free(s);
	return (arr);
}
