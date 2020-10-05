/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:40:32 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 15:29:12 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <fcntl.h>

void	exit_error(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}

void	start_end_check(t_lemin *lemin)
{
	if (ft_strcmp(lemin->line, "##start") == 0)
	{
		if (lemin->start)
			exit_error();
		lemin->start_end = 1;
	}
	if (ft_strcmp(lemin->line, "##end") == 0)
	{
		if (lemin->end)
			exit_error();
		lemin->start_end = 2;
	}
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

int		main(int argc, char **argv)
{
	t_lemin		*lemin;
	t_room		*rooms;

	rooms = NULL;
	if (!(lemin = (t_lemin*)malloc(sizeof(t_lemin))))
		return (-1);
	initialize(lemin);
	parse_flags(lemin, argv, argc);
	number_of_ants(lemin);
	rooms = parse_rooms(lemin, rooms);
	rooms = parse_links(lemin, rooms);
	find_paths(lemin, rooms);
	if (check_req(lemin))
		init_round2(lemin, rooms);
	if (lemin->flags[1] == 1)
		print_results(lemin->result_paths);
	optimizate_paths_to_use(lemin, rooms);
	init_result(lemin);
	if (lemin->flags[0] == 1)
		ft_printf("#lines: %d\n", lemin->lines);
	return (0);
}
