/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:22:47 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 13:30:36 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	number_of_ants(t_lemin *lemin)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(lemin->fd, &line) > 0)
	{
		if (line[0] != '#')
			break ;
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_printf("%s\n", line);
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
	t_room		*next;
	t_room		*tmp;

	if (!(next = (t_room*)malloc(sizeof(t_room))))
		exit_error();
	next->name = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	lemin->rooms++;
	next->next = NULL;
	next->links = NULL;
	next->count = 0;
	next->visited = -1;
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
	while (get_next_line(lemin->fd, &lemin->line) > 0)
	{
		ft_putendl(lemin->line);
		if (!ft_strchr(lemin->line, ' ') && lemin->line[0] != '#')
			break ;
		start_end_check(lemin);
		if (lemin->line[0] != '#')
		{
			if (lemin->line[0] == 'L')
				exit_error();
			room = add_room(lemin, room, lemin->line);
			if (lemin->start_end == 1)
				lemin->start = ft_strsub(lemin->line, 0,
				ft_strchr(lemin->line, ' ') - lemin->line);
			else if (lemin->start_end == 2)
				lemin->end = ft_strsub(lemin->line, 0,
				ft_strchr(lemin->line, ' ') - lemin->line);
			lemin->start_end = 0;
		}
		ft_strdel(&lemin->line);
	}
	if (lemin->start == NULL || lemin->end == NULL)
		exit_error();
	return (room);
}

void	init_result_paths(t_lemin *lemin, t_room *room)
{
	int		i;
	char	**arr;

	i = 0;
	if (!(arr = malloc(sizeof(char*) * lemin->rooms)))
		exit_error();
	arr[0] = NULL;
	lemin->start_room = find_room(room, lemin->start);
	lemin->end_room = find_room(room, lemin->end);
	count_start_end_links(lemin);
	lemin->result_paths = arr;
}

t_room	*parse_links(t_lemin *lemin, t_room *room)
{
	if (lemin->line)
		room = get_first_links(lemin, room);
	while (get_next_line(lemin->fd, &lemin->line) > 0)
	{
		ft_putendl(lemin->line);
		if (lemin->line[0] != '#')
		{
			if (!ft_strchr(lemin->line, '-'))
				exit_error();
			init_link(lemin, room, ft_strsplit(lemin->line, '-'));
		}
		else if (ft_strncmp(lemin->line,
		"#Here is the number of lines required: :", 39) == 0)
			lemin->req = ft_atoi(lemin->line + 39);
		ft_strdel(&lemin->line);
	}
	if (lemin->check_start == 0 || lemin->check_end == 0)
		exit_error();
	init_result_paths(lemin, room);
	init_id(lemin, room);
	return (room);
}
