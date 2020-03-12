/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:40:32 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/12 16:00:28 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	exit_error()
{
	ft_putendl("ERROR\n");
	exit(EXIT_FAILURE);
}

void	print_results(char **arr)
{
	int		y;

	y = 0;
	while (arr[y])
	{
		if (arr[y][0] == '\0')
			break ;
		ft_printf("result: %s\n", arr[y]);
		y++;
	}
}

void	initialize(t_lemin *lemin)
{
	lemin->ants = 0;
	lemin->rooms = 0;
	lemin->amount = 0;
	lemin->length = 0;
	lemin->moves = NULL;
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->paths = NULL;
	lemin->line = NULL;
	lemin->result_paths = NULL;
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
	find_paths(lemin, rooms);
	print_results(lemin->result_paths);
	optimizate_paths_to_use(lemin, rooms);
	return (0);
}
