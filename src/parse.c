/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:24:45 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/12 16:03:48 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	number_of_ants(t_lemin *lemin)
{
	char	*line;
	int		i;

	i = 0;
	if (get_next_line(0, &line) < 1)
		exit_error();
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			exit_error();
		i++;
	}
	if ((lemin->ants = ft_atoi((const char*)line)) < 1)
		exit_error();
	ft_strdel(&line);
}

t_room	*add_room(t_lemin *lemin, t_room *rooms, char *line)
{
	t_room	*next;
	t_room *tmp;

	if (!(next = (t_room*)malloc(sizeof(t_room))))
		exit_error();
	next->name = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	lemin->rooms++;
	next->next = NULL;
	next->links = NULL;
	next->count = 0;
	next->visited = 0;
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

t_room	*parse_rooms(t_lemin *lemin, t_room *room)
{
	int		start_end;

	start_end = 0;
	while (get_next_line(0, &lemin->line) > 0)
	{
		if (!ft_strchr(lemin->line, ' ') && lemin->line[0] != '#')
			break ;
		if (ft_strcmp(lemin->line, "##start") == 0)
			start_end = 1;
		if (ft_strcmp(lemin->line, "##end") == 0)
			start_end = 2;
		if (lemin->line[0] != '#')
		{
			room = add_room(lemin, room, lemin->line);
			if (start_end == 1)
				lemin->start = ft_strsub(lemin->line, 0, ft_strchr(lemin->line, ' ') - lemin->line);
			else if (start_end == 2)
				lemin->end = ft_strsub(lemin->line, 0, ft_strchr(lemin->line, ' ') - lemin->line);
			start_end = 0;
		}
		ft_strdel(&lemin->line);
	}
	return (room);
}

char	**init_result_paths(t_lemin *lemin, char **arr)
{
	int		i;

	i = 0;
	if(!(arr = (char**)malloc(sizeof(char*) * lemin->rooms + 1)))
		exit_error();
	while (i < lemin->rooms)
	{
		arr[i] = ft_strnew(0);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_room	*parse_links(t_lemin *lemin, t_room *room)
{
	char	**links;

	if (lemin->line)
		room = get_first_links(lemin, room);
	while (get_next_line(0, &lemin->line) > 0)
	{
		if (!ft_strchr(lemin->line, '-') && lemin->line[0] != '#')
			break ;
		if (lemin->line[0] != '#')
		{
			links = ft_strsplit(lemin->line, '-');
			room = link_rooms(room, links[0], links[1]);
			room = link_rooms(room, links[1], links[0]);
			free(links);
		}
		ft_strdel(&lemin->line);
	}
	lemin->result_paths = init_result_paths(lemin, lemin->result_paths);
	return (room);
}
