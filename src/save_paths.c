/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:20:02 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/10 12:36:08 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		add_to_result_paths(t_lemin *lemin, char *str)
{
	int		y;

	y = 0;
	while (lemin->result_paths[y])
	{
		if (lemin->result_paths[y][0] == '\0')
			break ;
		y++;
	}
	lemin->result_paths[y] = ft_strdup(str);
	return (1);
}

int		check_end(t_lemin *lemin, char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i] != '-' || i == 0)
		i--;
	if (ft_strcmp(str + i + 1, lemin->end) != 0)
		return (0);
	return (1);
}

char	*combine_paths(t_lemin *lemin)
{
	char	*str;
	int		y;
	int		count;
	int		length;

	count = -1;
	y = -1;
	length = 0;
	while (lemin->result_paths[++count])
		if (lemin->result_paths[count][0] == '\0')
			break ;
	while (++y < count)
		length += ft_strlen(lemin->result_paths[y]) - 1;
	if (!(str = (char*)malloc(sizeof(char) * length + count + 1)))
		exit_error();
	y = 0;
	while (y < count)
	{
		ft_strcat(str, lemin->result_paths[y]);
		if (y + 1 != count)
			ft_strcat(str, "-");
		y++;
	}
	return (str);
}

int		check_if_possible_paths(t_lemin *lemin, t_room *room)
{
	t_room	*tmp;
	t_link	*links;

	tmp = find_room(room, lemin->start);
	links = tmp->links;
	while (links)
	{
		if (links->room_link->visited == 0)
			return (1);
		links = links->next;
	}
	return (0);
}

int		save_and_clear(t_lemin *lemin, t_room *room, int i)
{
	t_room	*tmp;
	char	**arr;
	char	*str;

	lemin->moves = ft_strdup(lemin->paths[i]);
	free(lemin->paths);
	tmp = room;
	if (check_end(lemin, lemin->moves) == 1)
		add_to_result_paths(lemin, lemin->moves);
	str = combine_paths(lemin);
	arr = ft_strsplit(str, '-');
	while (tmp)
	{
		if (search_name(lemin, arr, tmp->name) == 1)
			tmp->visited = 0;
		tmp = tmp->next;
	}
	return (check_end(lemin, lemin->moves));
}
