/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:06:50 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 18:36:45 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t length;

	i = 0;
	length = ft_strlen(dest);
	while (src[i])
	{
		dest[length] = src[i];
		length++;
		i++;
	}
	dest[length] = '\0';
	return (dest);
}
