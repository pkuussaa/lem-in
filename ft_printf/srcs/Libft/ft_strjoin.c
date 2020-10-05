/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:40:06 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 16:32:53 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	i = ft_strlen((char*)s1);
	i += ft_strlen((char*)s2);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	str = ft_strcpy(str, (char*)s1);
	i = ft_strlen((char*)s1);
	ft_strcpy((str + i), s2);
	return (str);
}
