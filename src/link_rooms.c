/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:37:17 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/09/29 17:27:37 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room	*find_room(t_room *room, char *name)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*find_free(t_room *room, char *name)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
		{
			ft_strdel(&name);
			return (tmp);
		}
		tmp = tmp->next;
	}
	ft_strdel(&name);
	return (NULL);
}

t_link	*loop_link(t_link *tmp_link, char *dst)
{
	while (tmp_link->next)
	{
		if (ft_strcmp(tmp_link->room_link->name, dst) == 0)
			exit_error();
		tmp_link = tmp_link->next;
	}
	return (tmp_link);
}

t_room	*link_rooms(t_room *room, char *src, char *dst)
{
	t_room	*tmp;
	t_room	*tmp2;
	t_link	*tmp_link;
	t_link	*new;

	if (!(tmp = find_room(room, src)) || !ft_strcmp(src, dst))
		exit_error();
	if (!(tmp2 = find_room(room, dst)) || !ft_strcmp(src, dst))
		exit_error();
	if (!(new = (t_link*)malloc(sizeof(t_link))))
		exit_error();
	new->room_link = tmp2;
	new->next = NULL;
	if (!tmp->links)
		tmp->links = new;
	else
	{
		tmp_link = tmp->links;
		tmp_link = loop_link(tmp_link, dst);
		tmp_link->next = new;
	}
	return (room);
}

t_room	*get_first_links(t_lemin *lemin, t_room *room)
{
	char	**links;

	if (!ft_strchr(lemin->line, '-') && lemin->line[0] != '#')
		exit_error();
	links = ft_strsplit(lemin->line, '-');
	check_path(lemin, links);
	room = link_rooms(room, links[0], links[1]);
	room = link_rooms(room, links[1], links[0]);
	free_2d_array(links);
	ft_strdel(&lemin->line);
	return (room);
}
