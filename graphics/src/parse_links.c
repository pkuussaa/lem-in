/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:20:24 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/15 16:20:49 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	parse_links(t_graphics *info, t_room *room)
{
	char	*tmp;
	char	*tmp2;

	if (info->line)
		tmp2 = ft_strdup(info->line);
	tmp = ft_strjoin(tmp2, " ");
	ft_strdel(&tmp2);
	while (get_next_line(0, &info->line) > 0)
	{
		if (info->line[0] == '\0')
			break ;
		tmp2 = ft_strjoin(ft_strdup(info->line), " ");
		tmp = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp2);
		ft_strdel(&info->line);
	}
	info->links = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
}

void	parse_result(t_graphics *info)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strnew(0);
	while (get_next_line(0, &info->line) > 0)
	{
		if (info->line[0] == '\0')
			break ;
		if (info->line[0] == 'L' && ft_strchr(info->line, ' '))
		{
			if (tmp2[0] == '\0')
				tmp2 = ft_strjoin(info->line, "!");
			else
			{
				tmp = ft_strjoin(tmp2, info->line);
				ft_strdel(&tmp2);
				tmp2 = ft_strjoin(tmp, "!");
				ft_strdel(&tmp);
			}
		}
	}
	tmp = ft_strsub(tmp2, 0, ft_strlen(tmp2) - 2);
	ft_strdel(&tmp2);
	init_result_list(info, ft_strsplit(tmp, '!'));
	ft_strdel(&tmp);
}
