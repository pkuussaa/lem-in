/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:37:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/23 18:43:40 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (str1[i])
	{
		if (str2[i] != str1[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (str2[i] != '\0')
		return (str1[i] - str2[i]);
	else
		return (0);
}
