/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poista.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:40:00 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/22 17:50:34 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*get_next_point(t_lemin *lemin, char *str)
{
	char	*tmp;
	int		i[3];

	str = check_if_end(lemin, str);
	if (!str)
		return(NULL);
	i[0] = -1;
	i[2] = 0;
	tmp = ft_strnew(ft_strlen(str) * 2);
	while (str[++i[0]])
	{
		tmp[i[2]] = str[i[0]];
		if (str[i[0]] == '-' && str[i[0] + 1] != '\0')
		{
			i[1] = 0;
			while (str[i[0] + 1 + i[1]] != ' ' && str[i[0] + 1 + i[1]] != '\0')
				i[1]++;
			lemin->tmp = next_point(lemin, str + i[0] + 1, i[1]);
			tmp = ft_strcat(tmp, lemin->tmp);
			i[2] += ft_strlen(lemin->tmp);
			ft_strdel(&lemin->tmp);
			i[0] += i[1];
		}
		i[2]++;
	}
	ft_strdel(&str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}

char	*get_next_point(t_lemin *lemin, char *str)
{
	char	*tmp;
	char	*tmp2;
	int		x;
	int		i;

	str = check_if_end(lemin, str);
	i = 0;
	x = 0;
	tmp2 = ft_strnew(0);
	while (str[i])
	{
		tmp = ft_strjoin(tmp2, &str[i]);
		free(tmp2);
		tmp2 = ft_strdup(tmp);
		free(tmp);
		if (str[i] == '-' && str[i + 1] != '\0')
		{
			x = 0;
			while (str[i + 1 + x] != ' ' && str[i + 1 + x] != '\0')
				x++;
			lemin->tmp = next_point(lemin, str + i + 1, x);
			tmp = ft_strjoin(tmp2, lemin->tmp);
			free(tmp2);
			tmp2 = ft_strdup(tmp);
			ft_strdel(&tmp);
			free(lemin->tmp);
			i += x;
		}
		i++;
	}
	free(str);
	if (!tmp)
		return (tmp2);
	return (tmp);
}
