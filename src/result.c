/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:17:55 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/12 17:51:23 by pkuussaa         ###   ########.fr       */
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
	ft_printf("%s\n", moves[0]);
	while (ants < lemin->ants)
	{
		if (temp->count + path_length(lemin->result_paths[current]) >
		find_room(room, get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]))->count + path_length(lemin->result_paths[get_next_path(lemin->result_paths, current)]))
		{
			ft_printf("name: %s\n", find_room(room, get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]))->name);
			tmp = display_format(get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]), ft_itoa(ants + 1));
			ft_printf("tmp: %s\n", tmp);
			ants++;
			if (moves[i][0] != '\0')
			{
				tmp = ft_strjoin(" ", tmp);
				moves[i] = ft_strjoin(moves[i], tmp);
			}
			else
				moves[i] = ft_strdup(tmp);
			ft_strdel(&tmp);
			ft_printf("%s %d\n", moves[i], i);
			//temp = find_room(room, get_first_path_node(lemin->result_paths[get_next_path(lemin->result_paths, current)]));
			current = get_next_path(lemin->result_paths, current);
			ft_printf("temp %s\n", temp->name);
		}
		else
		{
			//break ;
			i++;
			tmp = display_format(get_first_path_node(lemin->result_paths[current]), ft_itoa(ants + 1));
			ft_printf("%d\n", i);
			ants++;
			if (moves[i][0] != '\0')
			{
				tmp = ft_strjoin(" ", tmp);
				moves[i] = ft_strjoin(moves[i], tmp);
			}
			else
				moves[i] = ft_strdup(tmp);
			ft_printf("%s %d\n", moves[i], i);
		}
	}
}
