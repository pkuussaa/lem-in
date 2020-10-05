/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:22:52 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/22 16:03:59 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s2[i] && s1[i] && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if ((i != n && !(s1[i] && s2[i])) && (s2[i] || s1[i]))
		return (0);
	return (1);
}
