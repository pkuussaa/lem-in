/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:43:29 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 16:58:15 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*print_string(t_lst *arr)
{
	char *str;

	str = va_arg(arr->args, char *);
	if (arr->period > -1)
		str = str == NULL ? ft_strsub("(null)", 0, arr->period) :
			ft_strsub(str, 0, arr->period);
	else
		str = str == NULL ? ft_strsub("(null)", 0, 7) :
			ft_strsub(str, 0, ft_strlen(str));
	if (arr->flag_arr[4] == '0' && arr->flag_arr[0] == '\0')
		print_zeros(arr, ft_strlen(str), 1);
	else if (arr->flag_arr[0] == '\0')
		print_min_width(arr, ft_strlen(str), 1);
	ft_putstr(str);
	if (arr->flag_arr[0] == '-')
		print_min_width(arr, ft_strlen(str), 1);
	arr->len += ft_strlen(str);
	free(str);
	return (arr);
}
