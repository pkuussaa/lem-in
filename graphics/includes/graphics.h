/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 12:44:35 by pyrykuussaa       #+#    #+#             */
/*   Updated: 2020/06/03 16:24:58 by pkuussaa         ###   ########.fr       */
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

typedef struct			s_graphics
{
	t_room				*room;
	int					ants;
	int					rooms;
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

void					result_rooms(t_graphics *info, t_room *room);
void					scan_paths(t_graphics *info, t_room *room, t_room *tmp, int check, int index);
void					draw_circles(t_graphics *info, t_room *room);
void					number_of_ants(t_graphics *info);
void					draw_background(t_graphics *info);
t_room					*parse_rooms(t_graphics *info, t_room *room);
t_room					*find_room(t_room *room, char *name);


#endif
