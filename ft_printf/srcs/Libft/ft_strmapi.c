/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:29:57 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 17:24:55 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	i = ft_strlen((char*)s);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	return (str);
}
