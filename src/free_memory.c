/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:35:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 13:54:25 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_result_path(char **arr, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_2d_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_2d_int(t_lemin *lemin, int **arr)
{
	int		i;

	i = 0;
	while (i < lemin->rooms)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_items(int *arr)
{
	free(arr);
}

char	*free_and_init(t_lemin *lemin, char *tmp, int i)
{
	char	*tmp2;

	lemin->tmp = ft_strdup(lemin->paths[i]);
	lemin->tmp2 = ft_strjoin(lemin->tmp, " ");
	ft_strdel(&lemin->tmp);
	lemin->tmp = get_next_point(lemin, tmp);
	tmp2 = ft_strjoin(lemin->tmp2, lemin->tmp);
	ft_strdel(&lemin->tmp2);
	ft_strdel(&lemin->tmp);
	ft_printf("%s\n", tmp2);
	tmp = ft_strdup(tmp2);
	ft_strdel(&tmp2);
	lemin->lines++;
	return (tmp);
}
