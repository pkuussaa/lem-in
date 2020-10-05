/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_through_tunnels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:41:20 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/08/25 14:11:05 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		check_hash(char **arr, int i)
{
	while (arr[i])
	{
		if (arr[i][0] == '#')
			return (1);
		i++;
	}
	free_2d_array(arr);
	return (0);
}

char	*check_if_end(t_lemin *lemin, char *str)
{
	int		i;
	int		x;
	char	**arr;

	i = -1;
	arr = ft_strsplit(str, ' ');
	while (arr[++i])
	{
		x = -1;
		while (arr[i][++x])
			if (arr[i][x] == '-' && arr[i][x + 1] != '\0')
				if (ft_strncmp(arr[i] + x + 1, lemin->end,
				ft_strlen(lemin->end)) == 0)
				{
					free(arr[i]);
					arr[i] = ft_strdup("#");
					break ;
				}
	}
	if (check_hash(arr, 0))
	{
		ft_strdel(&str);
		return (get_str(arr, 0));
	}
	return (str);
}

char	*next_point(t_lemin *lemin, char *str, int length)
{
	int		x;
	int		i[2];

	i[0] = -1;
	i[1] = 0;
	while (lemin->result_paths[++i[0]])
	{
		x = -1;
		while (lemin->result_paths[i[0]][++x])
			if (lemin->result_paths[i[0]][x] == '-' &&
			lemin->result_paths[i[0]][x + 1] != '\0')
				if (ft_strncmp(str, lemin->result_paths[i[0]] + x + 1, length)
				== 0 && (lemin->result_paths[i[0]][x + 1 + length] == '-' ||
				lemin->result_paths[i[0]][x + 1 + length] == '\0'))
				{
					while (lemin->result_paths[i[0]][x + 1] != '-')
						x++;
					while (lemin->result_paths[i[0]][x + 2 + i[1]] != '-' &&
					lemin->result_paths[i[0]][x + 2 + i[1]] != '\0')
						i[1]++;
					return (ft_strsub(lemin->result_paths[i[0]], x + 2, i[1]));
				}
	}
	return (NULL);
}

char	*get_next_point(t_lemin *lemin, char *str)
{
	char	*tmp;
	int		i[3];

	str = check_if_end(lemin, str);
	i[0] = -1;
	i[2] = 0;
	tmp = ft_strnew(ft_strlen(str) * 2);
	while (str[++i[0]])
	{
		tmp[i[2]] = str[i[0]];
		if (str[i[0]] == '-' && str[i[0] + 1] != '\0')
		{
			i[1] = 0;
			while (str[i[0] + 1 + i[1]] != ' ' && str[i[0] + 1 + i[1]] != '\0')
				i[1]++;
			lemin->tmp = next_point(lemin, str + i[0] + 1, i[1]);
			tmp = ft_strcat(tmp, lemin->tmp);
			i[2] += ft_strlen(lemin->tmp);
			ft_strdel(&lemin->tmp);
			i[0] += i[1];
		}
		i[2]++;
	}
	ft_strdel(&str);
	return (tmp);
}

void	init_result(t_lemin *lemin)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = ft_strdup(lemin->paths[0]);
	ft_printf("\n%s\n", tmp);
	while (lemin->paths[++i])
	{
		if (lemin->paths[i][0] == '\0')
			break ;
		tmp = free_and_init(lemin, tmp, i);
	}
	while (tmp[0] != '\0')
	{
		tmp2 = get_next_point(lemin, tmp);
		if (tmp2[0] != '\0')
		{
			ft_printf("%s\n", tmp2);
			lemin->lines++;
		}
		tmp = ft_strdup(tmp2);
		free(tmp2);
	}
	ft_strdel(&tmp);
}
