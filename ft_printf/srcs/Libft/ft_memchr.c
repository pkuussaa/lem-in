/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:59:31 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 17:59:43 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *(char*)(str + i))
	{
		if (*(char*)(str + i) == c)
			return ((char*)(str + i));
		i++;
	}
	if (*(char*)(str + i) == c && c == '\0')
		return ((char*)(str + i));
	return (NULL);
}
