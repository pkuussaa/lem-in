/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_printed_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:31:38 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 13:51:02 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*choose_printed_arg(t_lst *arr)
{
	if (arr->arg_type == 'c')
		print_char(arr);
	else if (arr->arg_type == 'i' || arr->arg_type == 'd')
		print_int(arr);
	else if (arr->arg_type == 's')
		print_string(arr);
	else if (arr->arg_type == 'p')
		print_pointer(arr);
	else if (arr->arg_type == 'f')
		print_double(arr);
	else if (arr->arg_type == 'o')
		print_octal(arr);
	else if (arr->arg_type == '%')
		print_percent(arr);
	else if (arr->arg_type == 'u')
		print_u(arr);
	else if (arr->arg_type == 'x' || arr->arg_type == 'X')
		print_hexa(arr);
	return (arr);
}
