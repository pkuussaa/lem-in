/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:56:26 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 13:30:32 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char *source;
	unsigned char		*str;

	i = 0;
	source = src;
	str = dest;
	if (str < source)
		while (i < n)
		{
			str[i] = source[i];
			i++;
		}
	else if (str > source)
	{
		i = n;
		while (i > 0)
		{
			str[i - 1] = source[i - 1];
			i--;
		}
	}
	return (dest);
}
