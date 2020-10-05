/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 16:20:24 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/25 15:30:28 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	parse_start_end(t_graphics *info, int start_end)
{
	if (start_end == 1)
		info->start = ft_strsub(info->line, 0,
		ft_strchr(info->line, ' ') - info->line);
	else if (start_end == 2)
		info->end = ft_strsub(info->line, 0,
		ft_strchr(info->line, ' ') - info->line);
}

char	*init_link(t_graphics *info, char *tmp, char *tmp2)
{
	tmp2 = ft_strjoin(info->line, " ");
	info->tmp = ft_strjoin(tmp, tmp2);
	ft_strdel(&tmp);
	tmp = ft_strdup(info->tmp);
	ft_strdel(&info->tmp);
	ft_strdel(&tmp2);
	return (tmp);
}

void	parse_links(t_graphics *info, t_room *room)
{
	char	*tmp;
	char	*tmp2;

	if (info->line)
		tmp2 = ft_strdup(info->line);
	tmp = ft_strjoin(tmp2, " ");
	ft_strdel(&tmp2);
	ft_strdel(&info->line);
	while (get_next_line(0, &info->line) > 0)
	{
		if (info->line[0] == '\0')
			break ;
		if (ft_strcmp(info->line, "ERROR") == 0)
			exit(EXIT_FAILURE);
		if (info->line[0] != '#')
			tmp = init_link(info, tmp, tmp2);
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
	ft_strdel(&info->line);
	while (get_next_line(0, &info->line) > 0)
	{
		if (info->line[0] == '\0')
			break ;
		if (ft_strcmp(info->line, "ERROR") == 0)
			exit(EXIT_FAILURE);
		if (info->line[0] == 'L')
			tmp2 = free_and_join(info, tmp, tmp2);
		ft_strdel(&info->line);
	}
	if (tmp2[0] == '\0')
		exit(EXIT_FAILURE);
	tmp = ft_strsub(tmp2, 0, ft_strlen(tmp2) - 2);
	ft_strdel(&tmp2);
	init_result_list(info, ft_strsplit(tmp, '!'));
	ft_strdel(&tmp);
}
