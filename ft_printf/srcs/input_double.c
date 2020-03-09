/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:20:07 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 14:50:28 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	t_lst			*double_algorithm(t_lst *arr, long double i)
{
	int			count;
	int			times;
	uintmax_t	length;

	length = 0;
	count = arr->period;
	write(1, ".", 1);
	arr->len++;
	times = 0;
	while (count > 0)
	{
		i *= 10;
		length = (uintmax_t)i;
		i -= length;
		ft_putnbr(length);
		arr->len++;
		count--;
	}
	return (arr);
}

t_lst					*input_double(t_lst *arr, long double i)
{
	long long int	integer;
	int				count;
	char			*str;

	if (arr->period == -1)
		arr->period = 6;
	count = arr->period;
	integer = (long long int)i;
	str = hype_itoa((intmax_t)i);
	ft_putstr(str);
	arr->len += get_nbr_count(integer);
	i -= integer;
	if (arr->period != 0)
		double_algorithm(arr, i);
	free(str);
	return (arr);
}
