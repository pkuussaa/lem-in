/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:37:22 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 17:41:34 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_lst *arr;

	if (!(arr = (t_lst *)malloc(sizeof(t_lst))))
		return (-1);
	arr->copy = (char *)format;
	arr = set_values(arr);
	if (format)
	{
		va_start(arr->args, format);
		arr->len = parse_variables(arr);
		va_end(arr->args);
	}
	free(arr);
	return (arr->len);
}
