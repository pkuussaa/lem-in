/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/17 14:02:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		isEmpty(t_queue *queue)
{
	if(queue->rear == -1)
		return 1;
	return 0;
}

void	enqueue(t_queue *queue, char *value)
{
	if(queue->front == -1)
		queue->front = 0;
	queue->rear += 1;
	queue->items[queue->rear] = ft_strdup(value);
}

char	*dequeue(t_queue *q)
{
	char *item;
	if(isEmpty(q))
		item = "-1";
	else
	{
		item = q->items[q->front];
		q->front++;
		if(q->front > q->rear)
			q->front = q->rear = -1;
	}
	return item;
}

t_queue		*init_queue(t_queue *queue, t_lemin *lemin)
{
	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		exit_error();
	if (!(queue->items = (char**)malloc(sizeof(char*) * lemin->rooms)))
		exit_error();
	queue->front = -1;
	queue->rear = -1;
	return (queue);
}

char	*init_str(t_lemin *lemin, char *str, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str, str2);
	if (ft_strcmp(str2, lemin->end) == 0)
		return (tmp);
	return (ft_strjoin(tmp, "-"));
}

char	**init_array(t_lemin *lemin, char *name)
{
	char	**array;
	int		i;

	i = 0;
	if (!(array = (char**)malloc(sizeof(char*) * lemin->rooms + 1)))
		exit_error();
	while (i < lemin->rooms)
	{
		array[i] = ft_strnew(100);
		array[i] = ft_strncpy(array[i], name, ft_strlen(name));
		array[i] = ft_strcat(array[i], "-");
		i++;
	}
	array[i] = NULL;
	return (array);
}

int		find_empty(t_lemin *lemin, char **str)
{
	int		y;
	char	*tmp;

	y = 0;
	tmp = ft_strjoin(lemin->start, "-");
	while (str[y])
	{
		if (ft_strcmp(str[y], tmp) == 0)
			return (y);
		y++;
	}
	return (0);
}

char	*cut_last_node(char *str)
{
	int		i;
	char	*tmp;

	i = ft_strlen(str) - 2;
	while (str[i] != '-' || i == 0)
		i--;
	tmp = ft_strsub(str, 0, i + 1);
	return (tmp);
}

int		get_next_slot(t_lemin *lemin, char *str)
{
	int		y;
	int		i;
	int		res;
	char	**arr;

	y = 0;
	i = 0;
	res = 0;
	while (lemin->paths[i])
	{
		arr = ft_strsplit(lemin->paths[i], '-');
		while (arr[y])
		{
			if (ft_strcmp(arr[y], str) == 0)
			{
				res = find_empty(lemin, lemin->paths);
				ft_strdel(&lemin->paths[res]);
				lemin->paths[res] = cut_last_node(lemin->paths[i]);
				return (res);
			}
			y++;
		}
		y = 0;
		free(arr);
		i++;
	}
	return (0);
}

int		current_index(t_lemin *lemin, char *str)
{
	char	**arr;
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (lemin->paths[i])
	{
		arr = ft_strsplit(lemin->paths[i], '-');
		while (arr[y])
		{
			if (ft_strcmp(arr[y], str) == 0 && !arr[y + 1])
				return (i);
			y++;
		}
		y = 0;
		free(arr);
		i++;
	}
	return (get_next_slot(lemin, str));
}

t_link	*init_path(t_lemin **lemin, t_link *links, t_queue **queue, int *i)
{
	while (links)
	{
		if (links->room_link->visited == 0)
		{
			if ((*lemin)->length == 1)
				*i = current_index(*lemin, (*lemin)->currentnode);
			(*lemin)->paths[*i] = init_str(*lemin, (*lemin)->paths[*i], links->room_link->name);
			links->room_link->visited = 1;
			enqueue(*queue, links->room_link->name);
		}
		if (!links->next)
			break ;
		if ((*lemin)->length == 0)
			*i++;
		links = links->next;
	}
	return (links);
}

void	find_paths(t_lemin *lemin, t_room *room)
{
	t_queue		*queue;
	t_room		*tmp;
	t_link		*links;
	static int	i;

	queue = init_queue(queue, lemin);
	tmp = find_room(room, lemin->start);
	lemin->paths = init_array(lemin, tmp->name);
	tmp->visited = 1;
	enqueue(queue, tmp->name);
	while (!isEmpty(queue))
	{
		lemin->currentnode = dequeue(queue);
		//if (ft_strcmp(currentnode, lemin->end) == 0)
		//	break ;
		tmp = find_room(room, lemin->currentnode);
		links = tmp->links;
		//links = init_path(&lemin, links, &queue, &i);
		while (links)
		{
			if (links->room_link->visited == 0)
			{
				if (lemin->length == 1)
					i = current_index(lemin, lemin->currentnode);
				lemin->paths[i] = init_str(lemin, lemin->paths[i], links->room_link->name);
				links->room_link->visited = 1;
				enqueue(queue, links->room_link->name);
			}
			if (!links->next)
				break ;
			if (lemin->length == 0)
				i++;
			links = links->next;
		}
		lemin->length = 1;
		if (ft_strcmp(links->room_link->name, lemin->end) == 0)
			break ;
	}
	if (save_and_clear(lemin, room, i) == 1)
		find_paths(lemin, room);
}
