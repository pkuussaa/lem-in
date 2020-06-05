/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:58:04 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/05 16:15:37 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

void	number_of_ants(t_graphics *info)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) < 1)
		exit(EXIT_FAILURE);
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			exit(EXIT_FAILURE);
		i++;
	}
	if ((info->ants = ft_atoi((const char*)line)) < 1)
		exit(EXIT_FAILURE);
	ft_strdel(&line);
}

void	get_xy(t_room *room, char *src)
{
	char	**tmp;

	tmp = ft_strsplit(src, ' ');
	room->x = ft_atoi(tmp[0]);
	room->y = ft_atoi(tmp[1]);
	room->result = 0;
}

t_room	*add_room(t_graphics *info, t_room *rooms)
{
	t_room	*next;
	t_room	*tmp;
	char	*temp;

	if (!(next = (t_room*)malloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	temp = ft_strchr(info->line, ' ');
	get_xy(next, temp + 1);
	next->name = ft_strsub(info->line, 0, temp - info->line);
	info->rooms++;
	next->next = NULL;
	if (!rooms)
		rooms = next;
	else
	{
		tmp = rooms;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = next;
	}
	return (rooms);
}

t_room	*parse_rooms(t_graphics *info, t_room *room)
{
	int		start_end;

	start_end = 0;
	while (get_next_line(0, &info->line) > 0)
	{
		if (!ft_strchr(info->line, ' ') && info->line[0] != '#')
			break ;
		if (ft_strcmp(info->line, "##start") == 0)
			start_end = 1;
		if (ft_strcmp(info->line, "##end") == 0)
			start_end = 2;
		if (info->line[0] != '#')
		{
			room = add_room(info, room);
			if (start_end == 1)
				info->start = ft_strsub(info->line, 0, ft_strchr(info->line, ' ') - info->line);
			else if (start_end == 2)
				info->end = ft_strsub(info->line, 0, ft_strchr(info->line, ' ') - info->line);
			start_end = 0;
		}
		ft_strdel(&info->line);
	}
	return (room);
}


void	result_rooms(t_graphics *info, t_room *room)
{
	char	**tmp;
	int		i;

	while (get_next_line(0, &info->line) > 0)
	{
		if (info->line[0] == '\0')
			break ;
		if (ft_strncmp(info->line, "result:", 7) == 0)
		{
			tmp = ft_strsplit(ft_strsub(info->line, 8, ft_strlen(info->line) - 8), '-');
			i = 0;
			while (tmp[i])
			{
				find_room(room, tmp[i])->result = 1;
				i++;
			}
		}
	}
}

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

void	init_result_list(t_graphics *info, char **arr)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (arr[size])
		size++;
	if (!(info->result = (char***)malloc(sizeof(char**) * size + 1)))
		exit(EXIT_FAILURE);
	if (!(info->ant_moves = (double***)malloc(sizeof(double**) * size)))
		exit(EXIT_FAILURE);
	while (arr[i])
	{
		info->result[i] = ft_strsplit(arr[i], ' ');
		i++;
	}
	info->result[i] = NULL;
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
