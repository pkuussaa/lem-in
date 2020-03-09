/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:49:35 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/29 15:32:22 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_delim(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] == c)
		i++;
	i -= 1;
	return (i);
}

static	char	**mealloc(char *s, int i, char c)
{
	size_t	counter;
	char	**arr;

	counter = 1;
	i += 1;
	if (s[i] == '\0')
		counter = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c && s[i + 1] != '\0')
			counter++;
		if (s[i] == c && s[i - 1] == c && s[i + 1] == '\0')
			counter--;
		i++;
	}
	arr = (char**)malloc(sizeof(char*) * counter + 1);
	if (!arr)
		return (NULL);
	arr[counter] = NULL;
	return (arr);
}

static	size_t	check_c(char a, char c, int d)
{
	if (a != c)
		d++;
	return (d);
}

static	char	*copy_string(char *s, int i, int d, char c)
{
	char *dst;

	dst = ft_strnew(d);
	if (s[i + 1] == '\0' && s[i] != c)
		return (ft_strncpy(dst, (char*)(s + (i - (d - 1))), d));
	else
		return (ft_strncpy(dst, (char*)(s + (i - d)), d));
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	d;
	size_t	a;
	char	**arr;

	d = 0;
	a = 0;
	i = count_delim(s, c);
	if (!(arr = mealloc((char*)s, i, c)))
		return (NULL);
	while (s[++i])
	{
		d = check_c(s[i], c, d);
		if ((s[i] == c && s[i - 1] != c) || (s[i] == c && s[i - 1] != c &&
					s[i + 1] == '\0') || (s[i] != c && s[i + 1] == '\0'))
		{
			arr[a] = ft_strnew(d);
			arr[a] = copy_string((char*)s, i, d, c);
			d = 0;
			a++;
		}
	}
	return (arr);
}
