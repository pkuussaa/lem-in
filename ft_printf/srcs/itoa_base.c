/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:32:51 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 17:36:45 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	uintmax_t	negative(uintmax_t i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

char				*itoa_base(uintmax_t i, int base)
{
	char		*str;
	char		*tab;
	int			size;
	int			flag;
	uintmax_t	tmp;

	flag = 0;
	size = 0;
	tab = "0123456789abcdef";
	if (i < 0 && base == 10)
		flag = 1;
	tmp = i;
	while ((tmp = tmp / base))
		size++;
	size = size + flag + 1;
	str = ft_strnew(size);
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[negative(i % base)];
		size--;
		i = i / base;
	}
	return (str);
}
