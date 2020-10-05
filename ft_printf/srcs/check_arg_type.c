/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:43:06 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 16:03:06 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_lst	*check_arg_type(t_lst *arr)
{
	int i;

	i = 0;
	while (arr->arguments[i])
	{
		if (arr->copy[arr->i] == arr->arguments[i])
		{
			arr->arg_type = arr->copy[arr->i];
			arr->i++;
			break ;
		}
		i++;
	}
	return (arr);
}
