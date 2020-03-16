/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_through_tunnels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:04:46 by marvin            #+#    #+#             */
/*   Updated: 2020/03/16 13:04:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_length(char **arr)
{
	int i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

char	*get_str(char **arr, int i)
{
	char	*tmp;

	tmp = ft_strnew(0);
	while (arr[i])
	{
		if (arr[i][0] != '#')
		{
			tmp = ft_strjoin(tmp, arr[i]);
			if (arr[i + 1] != NULL)
				tmp = ft_strjoin(tmp, " ");
		}
		i++;
	}
	return (tmp);
}

int		check_hash(char **arr, int i)
{
	while (arr[i])
	{
		if (arr[i][0] == '#')
			return (1);
		i++;
	}
	return (0);
}

char	*check_if_end(t_lemin *lemin, char *str)
{
	int		i;
	int		x;
	char	**arr;

	i = 0;
	arr = ft_strsplit(str, ' ');
	while (arr[i])
	{
		x = 0;
		while (arr[i][x])
		{
			if (arr[i][x] == '-' && arr[i][x + 1] != '\0')
			{
				if (ft_strncmp(arr[i] + x + 1, lemin->end, ft_strlen(lemin->end)) == 0)
				{
					ft_bzero(arr[i], ft_strlen(arr[i]));
					arr[i] = ft_strcpy(arr[i], "#");
					break ;
				}
			}
			x++;
		}
		i++;
	}
	if (check_hash(arr, 0))
		return(get_str(arr, 0));
	return (str);
}

char	*next_point(t_lemin *lemin, char *str, int length)
{
	int		i;
	int		x;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (lemin->result_paths[i])
	{
		x = 0;
		while (lemin->result_paths[i][x])
		{
			if (lemin->result_paths[i][x] == '-' && lemin->result_paths[i][x + 1] != '\0')
			{
				if (ft_strncmp(str, lemin->result_paths[i] + x + 1, length) == 0 && (lemin->result_paths[i][x + 1 + length] == '-' || lemin->result_paths[i][x + 1 + length] == '\0'))
				{
					while (lemin->result_paths[i][x + 1] != '-')
						x++;
					while (lemin->result_paths[i][x + 2 + j] != '-' && lemin->result_paths[i][x + 2 + j] != '\0')
						j++;
					return (ft_strsub(lemin->result_paths[i], x + 2, j));
				}
			}
			x++;
		}
		i++;
	}
	return NULL;
}

char	*get_next_point(t_lemin *lemin, char *str)
{
	char	*result;
	char	*tmp;
	int		i;
	int		k;
	int		j;

	str = check_if_end(lemin, str);
	i = 0;
	k = 0;
	tmp = ft_strnew(ft_strlen(str) * 2);
	while (str[i])
	{
		tmp[k] = str[i];
		if (str[i] == '-' && str[i + 1] != '\0')
		{
			j = 0;
			while (str[i + 1 + j] != ' ' && str[i + 1 + j] != '\0')
				j++;
			ft_strcat(tmp, next_point(lemin, str + i + 1, j));
			k += ft_strlen(next_point(lemin, str + i + 1, j));
			i += j;
			if (str[i] == '\0')
				break ;
		}
		i++;
		k++;
	}
	return (tmp);
}

void	init_result(t_lemin *lemin, t_room *room)
{
	char	**result;
	char	*tmp;
	int		i;

	if (!(result = (char**)malloc(sizeof(char*) * get_length(lemin->paths) * 5))) // retu malloc
		exit_error();
	result[0] = ft_strdup(lemin->paths[0]);
	ft_printf("\n%s\n", result[0]);
	i = 1;
	while (lemin->paths[i])
	{
		if (lemin->paths[i][0] == '\0')
			break ;
		tmp = ft_strdup(lemin->paths[i]);
		tmp = ft_strjoin(tmp, " ");
		result[i] = ft_strjoin(tmp, get_next_point(lemin, result[i - 1]));
		ft_strdel(&tmp);
		ft_printf("%s\n", result[i]);
		i++;
	}
	while (result[i - 1][0] != '\0')
	{
		result[i] = get_next_point(lemin, result[i - 1]);
		ft_printf("%s\n", result[i]);
		i++;
	}
}
