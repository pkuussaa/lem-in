/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:44:39 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/11 14:22:12 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*cut_last_node(char *str)
{
	int		i;
	char	*tmp;

	i = ft_strlen(str) - 2;
	while (str[i] != '-' || i == 0)
		i--;
	tmp = ft_strsub(str, 0, i + 1);
	return (tmp);
}

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
	free_2d_array(arr);
	return (i - 2);
}

char	*get_first_path_node(char *str)
{
	char	**arr;
	char	*tmp;

	arr = ft_strsplit(str, '-');
	tmp = ft_strdup(arr[1]);
	free_2d_array(arr);
	return (tmp);
}

int		get_next_path(char **arr, int i)
{
	if (arr[i + 1][0] != '\0')
		return (i + 1);
	return (0);
}
