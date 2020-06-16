/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:40:32 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/16 17:54:38 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	exit_error(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}

void	print_results(char **arr)
{
	int		y;

	y = 0;
	ft_printf("\n");
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
	lemin->start_end = 0;
	lemin->i = 0;
	lemin->i2 = 0;
	lemin->current = 0;
	lemin->count = 0;
	lemin->count_ants = 1;
	lemin->rooms = 0;
	lemin->amount = 0;
	lemin->length = 0;
	lemin->check_end = 0;
	lemin->check_start = 0;
	lemin->tmp = NULL;
	lemin->tmp2 = NULL;
	lemin->path_moves = NULL;
	lemin->currentnode = NULL;
	lemin->moves = ft_strnew(0);
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
	init_result(lemin, rooms);
	return (0);
}
