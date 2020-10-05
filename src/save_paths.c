/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:20:02 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 14:03:57 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		add_to_result_paths(t_lemin *lemin, char *str)
{
	static int	y;
	static int	round;
	char		**arr;

	if (round < lemin->round)
	{
		round = lemin->round;
		y = 0;
	}
	arr = lemin->round == 1 ? lemin->result_paths : lemin->result_paths2;
	if (y > 0)
		ft_strdel(&arr[y]);
	arr[y] = ft_strdup(str);
	arr[y + 1] = ft_strnew(0);
	y += 1;
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

char	*combine_paths(t_lemin *lemin, int count, int y)
{
	char	*tmp;
	char	*tmp2;
	char	**arr;

	arr = lemin->round == 1 ? lemin->result_paths : lemin->result_paths2;
	if (!arr[0])
		exit_error();
	while (arr[count++])
		if (arr[count][0] == '\0')
			break ;
	y = 1;
	tmp = ft_strjoin(arr[0], "-");
	while (y < count)
	{
		tmp2 = ft_strjoin(tmp, arr[y]);
		free(tmp);
		tmp = y + 1 != count ? ft_strjoin(tmp2, "-") : ft_strdup(tmp2);
		free(tmp2);
		y++;
	}
	return (tmp);
}

t_room	*find_room_with_number(t_room *room, int number)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->number == number)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		save_and_clear(t_lemin *lemin, t_room *room, int i)
{
	char	**arr;
	char	*str;

	free(lemin->moves);
	lemin->moves = init_result_path(lemin, room, lemin->int_paths[i]);
	free_2d_int(lemin, lemin->int_paths);
	if (check_end(lemin, lemin->moves) == 1)
	{
		add_to_result_paths(lemin, lemin->moves);
		if (enough_paths(lemin, 0, 0, 0))
			delete_last(lemin);
	}
	if (lemin->round == 2 && lemin->result_paths2[0] == NULL)
	{
		lemin->result_paths2[0] = ft_strnew(0);
		lemin->result_paths2[1] = NULL;
		return (0);
	}
	str = combine_paths(lemin, 0, -1);
	arr = ft_strsplit(str, '-');
	reset_visit_values(lemin, room, arr, str);
	if (lemin->last == 1)
		return (0);
	return (check_end(lemin, lemin->moves));
}
