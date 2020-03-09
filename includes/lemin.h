/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:31:59 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/09 18:39:01 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_room	t_room;
typedef struct s_link	t_link;

struct					s_room
{
	char				*name;
	int					visited;
	t_link				*links;
	t_room				*next;
};

struct					s_link
{
	t_room				*room_link;
	t_link				*next;
};

typedef struct			s_lemin
{
	int					ants;
	int					rooms;
	char				**paths;
	char				*line;
	char				*start;
	char				*end;
}						t_lemin;

void					number_of_ants(t_lemin *lemin);
t_room					*parse_rooms(t_lemin *lemin, t_room *room);
t_room					*parse_links(t_lemin *lemin, t_room *room);
t_room					*get_first_links(t_lemin *lemin, t_room *room);
t_room					*link_rooms(t_room *room, char *src, char *dst);
void					exit_error();

#endif
