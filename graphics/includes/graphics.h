/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:44:35 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/09 19:12:13 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include <mlx.h>
# include "../../get_next_line/get_next_line.h"
# include "../../ft_printf/includes/ft_printf.h"

typedef struct s_room	t_room;

struct					s_room
{
	int					x;
	int					y;
	int					result;
	char				*name;
	t_room				*next;
};

typedef struct			s_ants
{
	int					name;
	char				*room_name;
}						t_ants;

typedef struct			s_graphics
{
	t_ants				**ant;
	t_room				*room;
	double				***ant_moves;
	double				****paths;
	int					*size;
	int					loop;
	int					y;
	int					index;
	int					stop;
	int					**indexes;
	int					ants;
	int					rooms;
	char				***result;
	char				**links;
	char				*line;
	char				*start;
	char				*end;
	void				*mlx;
	void				*ptr;
	void				*img;
	int					bits_per_pixel;
	char				*data_addr;
	int					size_line;
	int					endian;
	int					color;
}						t_graphics;

void					draw_ant(t_graphics *info, double *list);
void					parse_result(t_graphics *info);
void					draw_links(t_graphics *info, t_room *room);
void					parse_links(t_graphics *info, t_room *room);
void					result_rooms(t_graphics *info, t_room *room);
void					draw_circles(t_graphics *info, t_room *room, int radius);
void					number_of_ants(t_graphics *info);
void					draw_background(t_graphics *info);

t_room					*parse_rooms(t_graphics *info, t_room *room);
t_room					*find_room(t_room *room, char *name);

int						scan_paths(t_graphics *info, t_room *room, t_room *tmp);
int						move_ants(t_graphics *info, t_ants **ants);

double					*get_draw_coordinates(double *arr);
double					*handle_link(t_room *room, char **links);
double					*init_list_int(double x, double y);
double	*init_list(double start_x, double start_y, double end_x,
													double end_y);
double					**moving_algorithm(t_graphics *info, double *arr);

#endif
