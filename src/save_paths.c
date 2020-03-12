/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:20:02 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/12 15:00:52 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		search_name(t_lemin *lemin, char **arr, char *name)
{
	int		y;

	y = 0;
	while (arr[y])
	{
		if (arr[y][0] != '\0')
		{
			if (ft_strcmp(name, lemin->start) == 0 ||
					ft_strcmp(name, lemin->end) == 0)
				return (1);
			if (ft_strcmp(arr[y], name) == 0)
				return (0);
		}
		y++;
	}
	return (1);
}

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

	count = 0;
	y = 0;
	length = 0;
	while (lemin->result_paths[count])
	{
		if (lemin->result_paths[count][0] == '\0')
			break ;
		count++;
	}
	while (y < count)
	{
		length += ft_strlen(lemin->result_paths[y]) - 1;
		y++;
	}
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

/*int		char_count_until(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	return (i);
}

void	save_path(t_lemin *lemin, char *name, char *link_name)
{
	int		count;
	int		i;

	i = 0;
	if (!lemin->paths)
	{
		if(!(lemin->paths = (char**)malloc(sizeof(char*))))
			exit_error();
		lemin->paths[0] = ft_strjoin(name, link_name);
		ft_printf("path %s\n", lemin->paths[0]);
		lemin->amount++;
		return ;
	}
	while (lemin->paths[i])
	{
		count = char_count_until(lemin->paths[0]);
		if (ft_strncmp(name, lemin->paths[i], count) == 0)
		{
			lemin->amount++;
			ft_printf("sdf %s\n", lemin->paths[0]);
			if(!(lemin->paths = (char**)malloc(sizeof(char*) * lemin->amount)))
				exit_error();
			ft_printf("sdf %s\n", lemin->paths[0]);
		}
	}
}

int		search_name(char **list, char *name)
{
	int y;

	y = 0;
	while (list[y])
	{
		ft_printf("name, %s, list, %s\n", name, list[y]);
		if (ft_strcmp(list[y], name) == 0)
			return (1);
		y++;
	}
	return (0);
}

void	print_visited(t_lemin *lemin, t_room *room)
{
	t_room	*tmp;
	t_link	*links;

	tmp = room;
	links = room->links;

	while (tmp)
	{
		ft_printf("visited: %s %d\n", tmp->name, tmp->visited);
		tmp = tmp->next;
	}
}


void	print_visited(t_lemin *lemin, t_room *room, t_room *tmp, t_link *links)
{
	static int	i;
	t_link		*tmp_link;

	tmp_link = links;
	while (tmp)
	{
		while (links)
		{
			if (links->room_link->visited == 1 && links->room_link->checked == 0)
			{
				links->room_link->checked = 1;
				lemin->paths[i] = init_str(lemin->paths[i], links->room_link->name);
				ft_printf("str: %s i: %d\n", lemin->paths[i], i);
			}
			//print_visited(lemin, room, find_room(room, links->room_link->name), find_room(room, links->room_link->name)->links);
			links = links->next;
			i++;
		}
		tmp = find_room(room, tmp_link->room_link->name);
		links = tmp->links;
		i = 0;
		//break ;
	}
}*/
