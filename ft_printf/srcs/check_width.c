/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:15:44 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/16 18:13:35 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*check_width(t_lst *arr)
{
	while (arr->copy[arr->i] >= '0' && arr->copy[arr->i] <= '9')
	{
		arr->field_width *= 10;
		arr->field_width += arr->copy[arr->i] - 48;
		arr->i++;
	}
	return (check_period(arr));
}
