/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:14:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 13:22:15 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t cnt)
{
	size_t i;

	i = 0;
	while (i < cnt && *(unsigned char*)(src + i) != (unsigned char)c)
	{
		*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
		i++;
		if (*(unsigned char*)(src + i) == (unsigned char)c)
		{
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
			return (dest + (i + 1));
		}
	}
	return (NULL);
}
