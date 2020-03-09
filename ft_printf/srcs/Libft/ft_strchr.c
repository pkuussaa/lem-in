/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:43:37 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/21 16:28:47 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)(str + i));
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char*)(str + i));
	return (NULL);
}
