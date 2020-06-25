/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:35:08 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/25 13:28:54 by pkuussaa         ###   ########.fr       */
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

char	*free_and_init(t_lemin *lemin, char *tmp, char *tmp2, int i)
{
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
	return (tmp);
}
