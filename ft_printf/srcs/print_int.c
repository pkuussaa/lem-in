/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:44:52 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 16:01:03 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	intmax_t	get_type(t_lst *arr, intmax_t i)
{
	if (ft_strcmp(arr->modifier_arr, "\0") == 0)
		i = (int)va_arg(arr->args, int);
	else if (ft_strcmp(arr->modifier_arr, "h") == 0)
		i = (short)va_arg(arr->args, int);
	else if (ft_strcmp(arr->modifier_arr, "hh") == 0)
		i = (signed char)va_arg(arr->args, int);
	else if (ft_strcmp(arr->modifier_arr, "l") == 0)
		i = (long)va_arg(arr->args, long int);
	else if (ft_strcmp(arr->modifier_arr, "ll") == 0)
		i = (long long)va_arg(arr->args, long long int);
	return ((intmax_t)i);
}

static	t_lst		*flag_zero(t_lst *arr, intmax_t i)
{
	char *str;

	str = hype_itoa(i);
	if (arr->period == -1)
	{
		print_plus(arr, i);
		if (arr->field_width > 0)
			arr->flag_arr[2] == '+' || arr->negative == -1 || arr->flag_arr[1]
				== ' ' ? print_zeros(arr, (get_nbr_count(i) + 1), i) :
				print_zeros(arr, get_nbr_count(i), i);
		ft_putstr(str);
		arr->len += ft_strlen(str);
	}
	else if (arr->period > -1)
		period(arr, i);
	free(str);
	return (arr);
}

static	t_lst		*min_width_check(t_lst *arr, intmax_t i)
{
	arr->flag_arr[2] == '+' || arr->negative == -1 ||
				arr->flag_arr[1] == ' ' ? print_min_width(arr, (get_nbr_count(i)
					+ 1), i) : print_min_width(arr, get_nbr_count(i), i);
	return (arr);
}

static	t_lst		*min_width_negative_flag(t_lst *arr, intmax_t i)
{
	arr->flag_arr[2] == '+' || arr->negative == -1 ||
				arr->flag_arr[1] == ' ' ? print_min_width(arr, (get_nbr_count(i)
					+ 1), i) : print_min_width(arr, get_nbr_count(i), i);
	return (arr);
}

t_lst				*print_int(t_lst *arr)
{
	intmax_t i;

	i = get_type(arr, 0);
	if (i < 0)
	{
		i *= -1;
		arr->negative = -1;
	}
	if ((arr->period > -1 && arr->flag_arr[4] == '\0') || (arr->period > -1
				&& arr->flag_arr[4] == '0' && arr->flag_arr[0] == '-'))
		period(arr, i);
	else if (!arr->flag_arr[4] || (arr->flag_arr[4] && arr->flag_arr[0]))
	{
		if (arr->field_width > 0 && arr->flag_arr[0] == '\0')
			min_width_check(arr, i);
		if (arr->period == -1)
			print_plus(arr, i);
		input_int(arr, i);
		if (arr->field_width > 0 && arr->flag_arr[0] == '-')
			min_width_negative_flag(arr, i);
	}
	else if (arr->flag_arr[4] == '0' && arr->flag_arr[0] == '\0')
		flag_zero(arr, i);
	return (arr);
}
