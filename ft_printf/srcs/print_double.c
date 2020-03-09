/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:20:41 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/20 18:33:47 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	long double		get_modifier(t_lst *arr)
{
	long double i;

	if (ft_strcmp(arr->modifier_arr, "L") == 0)
		i = (long double)va_arg(arr->args, long double);
	else
		i = (double)va_arg(arr->args, double);
	return ((long double)i);
}

static	int				double_length(t_lst *arr, long double i)
{
	int count;

	count = get_nbr_count((int)i);
	count += arr->period > 0 ? arr->period + 1 : 0;
	return (count);
}

static	long double		get_decimal(t_lst *arr, long double i)
{
	int			count;
	long double	factor;

	factor = arr->period == 0 ? 0.4999 : 0.5;
	count = 0;
	if (arr->period == -1)
		arr->period = 6;
	if (arr->period >= 0)
	{
		count = arr->period;
		while (count > 0)
		{
			factor /= 10;
			count--;
		}
		i = i + factor;
	}
	return (i);
}

static	t_lst			*field_width(t_lst *arr, long double i)
{
	if (arr->flag_arr[4] == '\0' || arr->flag_arr[0] == '-')
	{
		i = get_decimal(arr, i);
		arr->flag_arr[2] == '+' || (arr->flag_arr[1] == ' ' &&
		arr->negative == 1) ? print_min_width(arr, double_length(arr, i)
		+ 1, 1) : print_min_width(arr, double_length(arr, i), 1);
		if (arr->flag_arr[0] == '\0')
			print_plus(arr, 1);
	}
	else if (arr->flag_arr[4] == '0')
	{
		i = get_decimal(arr, i);
		print_plus(arr, 1);
		arr->flag_arr[2] == '+' ? print_zeros(arr, double_length(arr, i)
					+ 1, 1) : print_zeros(arr, double_length(arr, i), 1);
	}
	return (arr);
}

t_lst					*print_double(t_lst *arr)
{
	long double i;

	i = get_modifier(arr);
	if (i < 0)
	{
		arr->negative = -1;
		i *= -1;
	}
	if (arr->field_width > 0 && arr->flag_arr[0] == '\0')
		field_width(arr, i);
	else
		print_plus(arr, 1);
	i = get_decimal(arr, i);
	input_double(arr, i);
	if (arr->flag_arr[3] == '#' && arr->period == 0)
	{
		write(1, ".", 1);
		arr->len++;
	}
	if (arr->flag_arr[0] == '-')
		field_width(arr, i);
	return (arr);
}
