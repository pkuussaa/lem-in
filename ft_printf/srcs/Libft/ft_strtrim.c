/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:10:36 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 17:16:33 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	i = ft_strlen((char*)s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i != 0)
		i--;
	if (i != 0)
		len = i - start + 1;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = *(s + (start + i));
		i++;
	}
	return (str);
}
