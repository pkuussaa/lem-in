/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:49:22 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/09 15:50:21 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_recursive_itoa(int i, int counter)
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

char			*ft_itoa(int n)
{
	int		counter;
	char	*str;

	counter = 1;
	if (n < 0)
	{
		counter = 2;
	}
	if (!(str = ft_recursive_itoa(n, counter)))
		return (NULL);
	return (str);
}
