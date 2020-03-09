/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:40:21 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 18:32:03 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t length;
	size_t i;
	size_t res;
	size_t index;

	i = 0;
	length = ft_strlen(dst);
	index = length;
	if (dstsize > length)
	{
		while (i < (dstsize - length - 1))
		{
			if (dstsize == index + 1)
				break ;
			if (src[i] == '\0')
			{
				dst[index] = '\0';
				return (res = ft_strlen(src) + length);
			}
			dst[index++] = src[i++];
		}
		dst[index] = '\0';
		return (res = ft_strlen(src) + length);
	}
	return (ft_strlen(src) + dstsize);
}
