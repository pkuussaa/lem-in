/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:41:13 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 15:56:32 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		check_plus_in_int(t_lst *arr, int check,
		intmax_t i, int first)
{
	if (arr->flag_arr[2] == '+' && arr->period == 0 && i == 0 &&
			arr->flag_arr[0] == '-' && first == 1)
	{
		check = 1;
		write(1, "+", 1);
		arr->len++;
	}
	else if (arr->flag_arr[2] == '+' && arr->period == 0
			&& i == 0 && arr->flag_arr[0] == '\0' && first == 2)
	{
		check = 1;
		write(1, "+", 1);
		arr->len++;
	}
	return (check);
}

t_lst			*input_int(t_lst *arr, intmax_t i)
{
	int		check;
	char	*str;

	check = check_plus_in_int(arr, 0, i, 1);
	str = hype_itoa(i);
	check = arr->period == 0 && i == 0 ? 1 : check;
	if (arr->period == 0 && i == 0)
		if (arr->field_width > 0)
		{
			write(1, " ", 1);
			arr->len++;
		}
	check = check_plus_in_int(arr, check, i, 2);
	if (check == 0)
	{
		if (arr->flag_arr[2] == '+' && arr->period == 0 && i == 0)
			arr->period = 0;
		else
		{
			ft_putstr(str);
			arr->len += ft_strlen(str);
		}
	}
	free(str);
	return (arr);
}
