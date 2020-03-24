/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:17:55 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/13 17:02:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_path_count(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] == '\0')
			break ;
		i++;
	}
	return (i);
}

int		path_length(char *str)
{
	int		i;
	char	**arr;

	arr = ft_strsplit(str, '-');
	i = 0;
	while (arr[i])
		i++;
	return (i - 2);
}

char	*get_first_path_node(char *str)
{
	char	**arr;

	arr = ft_strsplit(str, '-');
	return (arr[1]);
}

char	*display_format(char *room, char *number)
{
	char	*tmp;

	tmp = ft_strjoin("L", number);
	ft_strdel(&number);
	number = ft_strjoin(tmp, "-");
	ft_strdel(&tmp);
	return (ft_strjoin(number, room));
}

int		get_next_path(char **arr, int i)
{
	if (arr[i + 1][0] != '\0')
		return (i + 1);
	return (0);
}

char	**init_moves(char **arr, int i)
{
	int		y;

	y = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * i + 1)))
		exit_error();
	while (y < i)
	{
		arr[y] = ft_strnew(0);
		y++;
	}
	arr[y] = NULL;
	return (arr);
}

int		get_next_move(char **arr, char *name, int i)
{
	int		x;

	x = 0;
		while (arr[i][x])
		{
			if (arr[i][x] == '-' && arr[i][x + 1] != '\0')
			{
				if (ft_strncmp(arr[i] + x + 1, name, ft_strlen(name)) == 0)
				{
					i++;
					x = 0;
				}
			}
			x++;
		}
	return (i);
}

void	print_moves(char **arr, int i)
{
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		if (arr[i][0] == '\0')
			break ;
		i++;
	}
}

void	optimizate_paths_to_use(t_lemin *lemin, t_room *room)
{
	int		count;
	char	**moves;
	int		ants;
	char	*tmp;
	t_room	*temp;
	int		i;
	int		current;

	count = get_path_count(lemin->result_paths);
	moves = init_moves(moves, lemin->ants);
	ants = 1;
	i = 0;
	current = 0;
	tmp = ft_strdup(get_first_path_node(lemin->result_paths[0]));
	temp = find_room(room, get_first_path_node(lemin->result_paths[0]));
	temp->count++;
	moves[i] = display_format(tmp, ft_itoa(ants));
	ft_strdel(&tmp);
	//ft_printf("%s %d\n", moves[0], i);
	while (ants < lemin->ants)
	{
		if (find_room(room, get_first_path_node(lemin->result_paths[current]))->count + path_length(lemin->result_paths[current]) >
		find_room(room, get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]))->count + path_length(lemin->result_paths[get_next_path(lemin->result_paths, current)]))
		{
			i = get_next_move(moves, get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]), 0);
			//ft_printf("name: %s\n", find_room(room, get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]))->name);
			tmp = display_format(get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]), ft_itoa(ants + 1));
			//ft_printf("tmp: %s\n", tmp);
			ants++;
			if (moves[i][0] != '\0')
			{
				tmp = ft_strjoin(" ", tmp);
				moves[i] = ft_strjoin(moves[i], tmp);
			}
			else
				moves[i] = ft_strdup(tmp);
			ft_strdel(&tmp);
			//ft_printf("%s %d\n", moves[i], i);
			find_room(room, get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]))->count++;
			current = get_next_path(lemin->result_paths, current);
		}
		else if (ft_strcmp(lemin->result_paths[0], lemin->result_paths[current]) != 0 &&
		find_room(room, get_first_path_node(lemin->result_paths[current]))->count + path_length(lemin->result_paths[current]) >
		find_room(room, get_first_path_node(lemin->result_paths[0]))->count + path_length(lemin->result_paths[0]))
		{
			i = get_next_move(moves, get_first_path_node(lemin->result_paths[0]), 0);
			tmp = display_format(get_first_path_node(lemin->result_paths[0]), ft_itoa(ants + 1));
			ants++;
			if (moves[i][0] != '\0')
			{
				tmp = ft_strjoin(" ", tmp);
				moves[i] = ft_strjoin(moves[i], tmp);
			}
			else
				moves[i] = ft_strdup(tmp);
			ft_strdel(&tmp);
			find_room(room, get_first_path_node(lemin->result_paths[0]))->count++;
			current = 0;
		}
		else
		{
			i = get_next_move(moves, get_first_path_node(lemin->result_paths[current]), 0);
			tmp = display_format(get_first_path_node(lemin->result_paths[current]), ft_itoa(ants + 1));
			//ft_printf("%d\n", i);
			ants++;
			if (moves[i][0] != '\0')
			{
				tmp = ft_strjoin(" ", tmp);
				moves[i] = ft_strjoin(moves[i], tmp);
			}
			else
				moves[i] = ft_strdup(tmp);
			find_room(room, get_first_path_node(lemin->result_paths[current]))->count++;
			//ft_printf("%s %d\n", moves[i], i);
		}
	}
	free(lemin->paths);
	lemin->paths = moves;
	print_moves(lemin->paths, 0);
}
