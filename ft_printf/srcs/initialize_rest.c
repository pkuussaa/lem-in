/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_rest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:33:31 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/20 19:10:40 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*initialize_rest(t_lst *arr)
{
	arr->arg_type = '\0';
	arr->flag_arr[0] = '\0';
	arr->flag_arr[1] = '\0';
	arr->flag_arr[2] = '\0';
	arr->flag_arr[3] = '\0';
	arr->flag_arr[4] = '\0';
	arr->flag_arr[5] = '\0';
	arr->modifier_arr[0] = '\0';
	arr->modifier_arr[1] = '\0';
	arr->modifier_arr[2] = '\0';
	arr->period = -1;
	arr->field_width = 0;
	arr->negative = 1;
	arr->zeros_printed = 0;
	arr->is_dot = 0;
	return (arr);
}
