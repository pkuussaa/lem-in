/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:35:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/24 19:01:26 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	free_2d_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

void	free_items(char **arr, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}

char	**free_and_init(t_lemin *lemin, char **result, int i)
{
	lemin->tmp = ft_strdup(lemin->paths[i]);
	lemin->tmp2 = ft_strjoin(lemin->tmp, " ");
	ft_strdel(&lemin->tmp);
	lemin->tmp = get_next_point(lemin, result[0]);
	result[1] = ft_strjoin(lemin->tmp2, lemin->tmp);
	ft_strdel(&lemin->tmp2);
	ft_strdel(&lemin->tmp);
	ft_printf("%s\n", result[1]);
	result[0] = ft_strdup(result[1]);
	ft_strdel(&result[1]);
	return (result);
}
