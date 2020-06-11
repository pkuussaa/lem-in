/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_through_tunnels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:41:20 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/11 17:11:55 by pkuussaa         ###   ########.fr       */
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
		x = 0;
		while (arr[i][x])
		{
			if (arr[i][x] == '-' && arr[i][x + 1] != '\0')
				if (ft_strncmp(arr[i] + x + 1, lemin->end,
				ft_strlen(lemin->end)) == 0)
				{
					ft_bzero(arr[i], ft_strlen(arr[i]));
					arr[i] = ft_strcpy(arr[i], "#");
					break ;
				}
			x++;
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
			ft_strcat(tmp, lemin->tmp);
			i[2] += ft_strlen(lemin->tmp);
			ft_strdel(&lemin->tmp);
			i[0] += i[1];
			if (str[i[0]] == '\0')
				break ;
		}
		i[2]++;
	}
	ft_strdel(&str);
	return (tmp);
}

void	init_result(t_lemin *lemin, t_room *room)
{
	char	**result;
	int		i;

	if (!(result = (char**)malloc(sizeof(char*) * get_l(lemin->paths) * 2)))
		exit_error();
	result[0] = ft_strdup(lemin->paths[0]);
	ft_printf("\n%s\n", result[0]);
	i = 0;
	while (lemin->paths[++i])
	{
		if (lemin->paths[i][0] == '\0')
			break ;
		lemin->tmp = ft_strdup(lemin->paths[i]);
		lemin->tmp2 = ft_strjoin(lemin->tmp, " ");
		ft_strdel(&lemin->tmp);
		lemin->tmp = get_next_point(lemin, result[i - 1]);
		result[i] = ft_strjoin(lemin->tmp2, lemin->tmp);
		ft_strdel(&lemin->tmp2);
		ft_strdel(&lemin->tmp);
		ft_printf("%s\n", result[i]);
	}
	while (result[i - 1][0] != '\0')
	{
		result[i] = get_next_point(lemin, result[i - 1]);
		ft_printf("%s\n", result[i]);
		i++;
	}
	ft_strdel(&result[i - 1]);
}
