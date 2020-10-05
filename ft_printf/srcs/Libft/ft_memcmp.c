/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:24:27 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 13:35:22 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t length)
{
	size_t i;

	i = 0;
	while (i < length && *(unsigned char*)(s1 + i) == *(unsigned char*)(s2 + i))
		i++;
	if (i == length)
		return (0);
	return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
}
