/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:31:59 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/10/05 13:07:19 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef struct s_result	t_result;

typedef struct			s_queue
{
	int					*items;
	int					front;
	int					rear;
}						t_queue;

struct					s_room
{
	char				*name;
	int					count;
	int					number;
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
	t_room				*start_room;
	t_room				*end_room;
	t_queue				*queue;
	int					end_links;
	int					start_links;
	int					fd;
	int					start_end;
	int					short_path;
	int					round;
	int					flags[3];
	int					i;
	int					i2;
	int					req;
	int					lines;
	int					path1_lines;
	int					path2_lines;
	int					path1_sum;
	int					path2_sum;
	int					path1_moves;
	int					last;
	int					path2_moves;
	int					check_start;
	int					check_end;
	int					current;
	int					count;
	int					start_id;
	int					end_id;
	int					count_ants;
	int					length;
	char				*moves;
	int					amount;
	int					**int_paths;
	int					currentnode;
	char				**path_moves;
	char				**result_paths;
	char				**result_paths2;
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
int						find_empty(int **str);
int						get_path_count(char **arr);
int						path_length(char *str);
int						get_next_path(char **arr, int i);
int						get_next_move(char **arr, char *name, int i);
int						check_if_more_paths(t_lemin *lemin);
int						short_path_return(t_lemin *lemin);
int						dequeue(t_queue *q);
int						check_req(t_lemin *lemin);
int						enough_paths(t_lemin *lemin, int i, int sum, int y);

char					*get_str(char **arr, int i);
char					*init_str(t_lemin *lemin, char *str, char *str2);
char					*get_first_path_node(char *str);
char					*display_format(char *room, char *number);
char					*init_result_path(t_lemin *lemin,
											t_room *room, int *arr);
char					*get_next_point(t_lemin *lemin, char *str);
char					**init_moves(char **arr, int i);
char					*free_and_init(t_lemin *lemin, char *tmp, int i);

void					init_result(t_lemin *lemin);
void					optimizate_paths_to_use(t_lemin *lemin, t_room *room);
void					print_visited(t_lemin *lemin,
						t_room *room, t_room *tmp, t_link *links);
void					number_of_ants(t_lemin *lemin);
void					save_path(t_lemin *lemin, char *name, char *link_name);
void					find_paths(t_lemin *lemin, t_room *room);
void					exit_error(void);
void					free_2d_array(char **arr);
void					free_items(int *arr);
void					enqueue(t_queue *queue, int value);
void					check_path(t_lemin *lemin, char **links);
void					start_end_check(t_lemin *lemin);
void					if_short_path(t_lemin *lemin);
void					count_start_end_links(t_lemin *lemin);
void					free_2d_int(t_lemin *lemin, int **arr);
void					init_next_slot(t_lemin *lemin, int i, int res);
void					init_round2(t_lemin *lemin, t_room *rooms);
void					delete_last(t_lemin *lemin);
void					initialize(t_lemin *lemin);
void					init_link(t_lemin *lemin, t_room *room, char **links);
void					init_id(t_lemin *lemin, t_room *room);
void					parse_flags(t_lemin *lemin, char **flags, int count);
void					reset_visit_values(t_lemin *lemin,
						t_room *tmp, char **arr, char *str);
void					init_array(t_lemin *lemin);
void					free_result_path(char **arr, int size);

t_room					*parse_rooms(t_lemin *lemin, t_room *room);
t_room					*parse_links(t_lemin *lemin, t_room *room);
t_room					*get_first_links(t_lemin *lemin, t_room *room);
t_room					*find_room(t_room *room, char *name);
t_room					*find_free(t_room *room, char *name);
t_room					*link_rooms(t_room *room, char *src, char *dst);
t_room					*find_room_with_number(t_room *room, int number);

t_queue					*init_queue(t_lemin *lemin);

#endif
