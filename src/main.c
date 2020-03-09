/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:40:32 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/09 18:52:26 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	exit_error()
{
	ft_putendl("ERROR\n");
	exit(EXIT_FAILURE);
}

void	initialize(t_lemin *lemin)
{
	lemin->ants = 0;
	lemin->rooms = 0;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->paths = NULL;
	lemin->line = NULL;
}

int		main(void)
{
	t_lemin		*lemin;
	t_room		*rooms;

	rooms = NULL;
	if (!(lemin = (t_lemin*)malloc(sizeof(t_lemin))))
		return (-1);
	initialize(lemin);
	number_of_ants(lemin);
	rooms = parse_rooms(lemin, rooms);
	rooms = parse_links(lemin, rooms);
	ft_printf("%d, %d, %s, %s\n", lemin->ants, lemin->rooms, rooms->name, rooms->next->name);
	return (0);
}
