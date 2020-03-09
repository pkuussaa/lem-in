/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:34:50 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/29 12:41:03 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *dest)
{
	size_t		i;
	size_t		index;

	i = 0;
	if (*src == '\0' && *dest == '\0')
		return ((char*)src);
	while (src[i])
	{
		index = 0;
		while (src[i + index] == dest[index] && src[i + index])
			index++;
		if (dest[index] == '\0')
			break ;
		i++;
	}
	if (*(src + i) == '\0')
		return (NULL);
	return ((char*)(src + i));
}
