/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:51:55 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 14:05:39 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_usage(void)
{
	ft_putendl("");
	ft_putendl("|¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯|");
	ft_putendl("| Usage:                                                    |");
	ft_putendl("|                                                           |");
	ft_putendl("|       ./lem-in [possible flags] < [map]                   |");
	ft_putendl("|       ./generator --flow-one | ./lem-in [flags]           |");
	ft_putendl("|       ./generator --big | ./lem-in [flags]                |");
	ft_putendl("|       ./generator --big-superposition | ./lem-in [flags]  |");
	ft_putendl("|                                                           |");
	ft_putendl("| Flags:                                                    |");
	ft_putendl("|                                                           |");
	ft_putendl("|       -h |	Show usage                                  |");
	ft_putendl("|       -l |	Show amount of used lines                   |");
	ft_putendl("|       -p |	Show result paths                           |");
	ft_putendl("|                                                           |");
	ft_putendl("|___________________________________________________________|");
	ft_putendl("");
	exit(EXIT_SUCCESS);
}

void	save_flag(t_lemin *lemin, char flag)
{
	if (flag == 'l')
		lemin->flags[0] = 1;
	else if (flag == 'p')
		lemin->flags[1] = 1;
	else if (flag == 'h')
		lemin->flags[2] = 1;
}

void	parse_flags(t_lemin *lemin, char **flags, int count)
{
	int		i;
	int		j;

	j = 1;
	if (count > 1)
	{
		while (flags[j] && flags[j][0] == '-')
		{
			i = 1;
			while (flags[j][i] && ft_strchr("lph", flags[j][i]))
				save_flag(lemin, flags[j][i++]);
			j++;
		}
	}
	if (lemin->flags[2] == 1)
		print_usage();
}
