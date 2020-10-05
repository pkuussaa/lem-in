/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_path_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:20:52 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 13:53:32 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*init_result_path(t_lemin *lemin, t_room *room, int *arr)
{
	char	*str;
	char	*tmp2;
	int		i;

	i = 1;
	str = ft_strjoin(find_room_with_number(room, arr[0])->name, "-");
	while (arr[i] != -1 && i < 500)
	{
		tmp2 = ft_strjoin(str, find_room_with_number(room, arr[i])->name);
		free(str);
		if (ft_strcmp(lemin->end,
		find_room_with_number(room, arr[i])->name) != 0)
			str = ft_strjoin(tmp2, "-");
		else
			str = ft_strdup(tmp2);
		free(tmp2);
		i++;
	}
	return (str);
}

int		enough_paths(t_lemin *lemin, int i, int sum, int y)
{
	int		cmp;
	char	**cmp_path;
	char	**arr;

	arr = lemin->round == 1 ? lemin->result_paths : lemin->result_paths2;
	if (arr[1][0] == '\0')
		return (0);
	cmp_path = ft_strsplit(lemin->moves, '-');
	while (cmp_path[i] != NULL)
		i++;
	cmp = i - 2;
	i = 0;
	free_2d_array(cmp_path);
	while (arr[y + 1][0] != '\0')
	{
		cmp_path = ft_strsplit(arr[y], '-');
		while (cmp_path[i] != NULL)
			i++;
		sum += (cmp - (i - 2));
		free_2d_array(cmp_path);
		y++;
		i = 0;
	}
	return (sum >= lemin->ants);
}

void	delete_last(t_lemin *lemin)
{
	int		i;
	char	**arr;

	i = 0;
	arr = lemin->round == 1 ? lemin->result_paths : lemin->result_paths2;
	while (arr[i][0] != '\0')
		i++;
	i -= 1;
	free(arr[i + 1]);
	free(arr[i]);
	arr[i] = ft_strnew(0);
	lemin->last = 1;
}
