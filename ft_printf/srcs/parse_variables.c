/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:58:04 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 17:01:24 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_variables(t_lst *arr)
{
	if (ft_strcmp(arr->copy, "%") == 0)
		return (0);
	while (arr->copy[arr->i])
	{
		if (arr->copy[arr->i] == '%')
		{
			initialize_rest(arr);
			arr->i++;
			check_flags(arr);
			choose_printed_arg(arr);
		}
		else
		{
			write(1, &arr->copy[arr->i], 1);
			arr->len++;
			arr->i++;
		}
	}
	return (arr->len);
}
