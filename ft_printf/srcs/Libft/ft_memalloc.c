/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:33:33 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 19:03:01 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;

	area = (void*)malloc(size);
	if (!area)
		return (NULL);
	while (size > 0)
	{
		size--;
		*(char*)(area + size) = 0;
	}
	return (area);
}
