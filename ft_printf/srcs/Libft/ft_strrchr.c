/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:48:45 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/21 16:30:33 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (str[i])
	{
		if (str[i] == c)
			res = (char*)(str + i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		res = (char*)(str + i);
	return (res);
}
