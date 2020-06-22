/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:31:59 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/22 14:48:09 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_room	t_room;
typedef struct s_link	t_link;

typedef struct			s_queue
{
	char				**items;
	int					front;
	int					rear;
}						t_queue;

struct					s_room
{
	char				*name;
	int					count;
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
	int					start_end;
	int					i;
	int					i2;
	int					check_start;
	int					check_end;
	int					current;
	int					count;
	int					count_ants;
	int					length;
	char				*moves;
	int					amount;
	char				*currentnode;
	char				**path_moves;
	char				**result_paths;
	char				**paths;
	char				*line;
	char				*tmp;
	char				*tmp2;
	char				*start;
	char				*end;
}						t_lemin;

int						search_name(t_lemin *lemin, char **arr, char *name);
int						save_and_clear(t_lemin *lemin, t_room *room, int i);
int						get_l(char **arr);
int						is_empty(t_queue *queue);
int						find_empty(t_lemin *lemin, char **str);
int						get_path_count(char **arr);
int						path_length(char *str);
int						get_next_path(char **arr, int i);
int						get_next_move(char **arr, char *name, int i);

char					*get_str(char **arr, int i);
char					*dequeue(t_queue *q);
char					*init_str(t_lemin *lemin, char *str, char *str2);
char					*cut_last_node(char *str);
char					*get_first_path_node(char *str);
char					*display_format(char *room, char *number);
char					*get_next_point(t_lemin *lemin, char *str);
char					**init_array(t_lemin *lemin, char *name);
char					**init_moves(char **arr, int i);
char					**free_and_init(t_lemin *lemin, char **result, int i);

void					init_result(t_lemin *lemin, t_room *room);
void					optimizate_paths_to_use(t_lemin *lemin, t_room *room);
void					print_visited(t_lemin *lemin,
						t_room *room, t_room *tmp, t_link *links);
void					number_of_ants(t_lemin *lemin);
void					save_path(t_lemin *lemin, char *name, char *link_name);
void					find_paths(t_lemin *lemin, t_room *room);
void					exit_error(void);
void					free_2d_array(char **arr);
void					free_items(char **arr, int length);
void					enqueue(t_queue *queue, char *value);
void					check_path(t_lemin *lemin, char **links);

t_room					*parse_rooms(t_lemin *lemin, t_room *room);
t_room					*parse_links(t_lemin *lemin, t_room *room);
t_room					*get_first_links(t_lemin *lemin, t_room *room);
t_room					*find_room(t_room *room, char *name);
t_room					*find_free(t_room *room, char *name);
t_room					*link_rooms(t_room *room, char *src, char *dst);

t_queue					*init_queue(t_queue *queue, t_lemin *lemin);

#endif
