/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hype_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:51:21 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/17 15:48:18 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char	*ft_recursive_itoa(intmax_t i, int counter)
{
	char a;
	char *str;

	if (i > -1)
		a = (i % 10) + '0';
	else
		a = (i % 10) * -1 + '0';
	if (i < 10 && i > -10)
	{
		if (!(str = ft_strnew(counter)))
			return (NULL);
		if (i < 0)
			ft_strncat(str, "-", 1);
		return (ft_strncat(str, &a, 1));
	}
	str = ft_recursive_itoa(i / 10, counter + 1);
	return (ft_strncat(str, &a, 1));
}

char			*hype_itoa(intmax_t n)
{
	int		counter;
	char	*str;

	counter = 1;
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("9223372036854775808"));
	if (n < 0)
	{
		counter = 2;
	}
	if (!(str = ft_recursive_itoa(n, counter)))
		return (NULL);
	return (str);
}
