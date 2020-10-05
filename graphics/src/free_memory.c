/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:41:15 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 16:16:28 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

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

char	*free_and_join(t_graphics *info, char *tmp, char *tmp2)
{
	if (tmp2[0] == '\0')
	{
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(info->line, "!");
	}
	else
	{
		tmp = ft_strjoin(tmp2, info->line);
		ft_strdel(&tmp2);
		tmp2 = ft_strjoin(tmp, "!");
		ft_strdel(&tmp);
	}
	return (tmp2);
}
