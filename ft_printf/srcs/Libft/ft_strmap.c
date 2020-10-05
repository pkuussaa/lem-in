/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:37:33 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/25 12:43:47 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	i = 0;
	i = ft_strlen((char*)s);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		*(str + i) = f(*(s + i));
		i++;
	}
	return (str);
}
