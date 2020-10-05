/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_period.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:45:01 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 15:03:24 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	t_lst		*negative_flag_int(t_lst *arr, intmax_t i)
{
	print_plus(arr, i);
	print_zeros(arr, get_nbr_count(i), i);
	input_int(arr, i);
	(arr->flag_arr[2] == '+' || arr->flag_arr[1] == ' ') && arr->negative == 1 ?
		print_min_width(arr, get_nbr_count(i) + arr->zeros_printed + 1, i) :
		print_min_width(arr, get_nbr_count(i) + arr->zeros_printed, i);
	return (arr);
}

static	t_lst		*period_checks(t_lst *arr, intmax_t i)
{
	int count;

	count = 0;
	if (arr->flag_arr[0] == '-')
		negative_flag_int(arr, i);
	if (arr->flag_arr[0] == '\0')
	{
		count = get_nbr_count(i) < arr->period ? get_nbr_count(i) +
			(arr->period - get_nbr_count(i)) : get_nbr_count(i);
		if ((arr->flag_arr[2] == '+' || arr->flag_arr[1] == ' ')
				&& arr->negative == 1)
			count++;
		print_min_width(arr, count, i);
		print_plus(arr, i);
		print_zeros(arr, get_nbr_count(i), i);
		input_int(arr, i);
	}
	return (arr);
}

t_lst				*period(t_lst *arr, intmax_t i)
{
	int		spaces;
	char	*str;

	str = hype_itoa(i);
	spaces = arr->period > arr->field_width ? 1 : 0;
	if (spaces == 1)
	{
		print_plus(arr, i);
		print_zeros(arr, get_nbr_count(i), i);
		ft_putstr(str);
		arr->len += ft_strlen((const char*)hype_itoa(i));
	}
	else
		period_checks(arr, i);
	free(str);
	return (arr);
}
