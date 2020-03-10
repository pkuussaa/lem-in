/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:20:02 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/10 18:45:07 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		char_count_until(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	return (i);
}

void	save_path(t_lemin *lemin, char *name, char *link_name)
{
	int		count;
	int		i;

	i = 0;
	if (!lemin->paths)
	{
		if(!(lemin->paths = (char**)malloc(sizeof(char*))))
			exit_error();
		lemin->paths[0] = ft_strjoin(name, link_name);
		ft_printf("path %s\n", lemin->paths[0]);
		lemin->amount++;
		return ;
	}
	while (lemin->paths[i])
	{
		count = char_count_until(lemin->paths[0]);
		if (ft_strncmp(name, lemin->paths[i], count) == 0)
		{
			lemin->amount++;
			ft_printf("sdf %s\n", lemin->paths[0]);
			if(!(lemin->paths = (char**)malloc(sizeof(char*) * lemin->amount)))
				exit_error();
			ft_printf("sdf %s\n", lemin->paths[0]);
		}
	}
}
