/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:55:58 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/29 12:40:29 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *dest, size_t len)
{
	size_t	i;
	size_t	index;

	i = 0;
	if ((src[i] == '\0' && len == 0) || (dest[i] == '\0' && len == 0))
		return ((char*)src);
	while (src[i] && i <= len)
	{
		index = 0;
		while (src[i + index] == dest[index] && i + index < len)
		{
			if (dest[index] == '\0')
				return ((char*)(src + i));
			index++;
		}
		if (dest[index] == '\0')
			return ((char*)(src + i));
		i++;
	}
	return (NULL);
}
