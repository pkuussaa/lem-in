/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:47:26 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 16:41:29 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < (size + 1))
	{
		str[i] = '\0';
		i++;
	}
	if (!str)
		return (NULL);
	return (str);
}
