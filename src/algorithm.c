/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:35:10 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/03/10 18:33:07 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		isEmpty(t_queue *queue)
{
	if(queue->rear == -1)
		return 1;
	else
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
	{
		//ft_printf("Queue is empty");
		item = "-1";
	}
	else
	{
		item = q->items[q->front];
		q->front++;
		if(q->front > q->rear)
		{
			//ft_printf("Resetting queue\n");
			q->front = q->rear = -1;
		}
	}
	return item;
}

void	printQueue(t_queue *queue)
{
	int i = queue->front;

	if(isEmpty(queue))
		ft_printf("Queue is empty\n");
	else
	{
		ft_printf("\nQueue contains \n");
		for(i = queue->front; i < queue->rear + 1; i++)
		{
			ft_printf("%s ", queue->items[i]);
		}
		ft_printf("\n");
	}
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

void	find_paths(t_lemin *lemin, t_room *room)
{
	t_queue	*queue;
	t_room	*tmp;
	t_link	*links;
	char	*currentnode;

	queue = init_queue(queue, lemin);
	tmp = find_room(room, lemin->start);
	lemin->moves = ft_strnew(0);
	tmp->visited = 1;
	enqueue(queue, tmp->name);
	while (!isEmpty(queue))
	{
		currentnode = dequeue(queue);
		if (ft_strcmp(currentnode, lemin->end) == 0)
			break ;
		tmp = find_room(room, currentnode);
		links = tmp->links;
		while (links)
		{
			/*if (tmp->visited == 0)
			{
				ft_printf("visited: %s\n", tmp->name);
				tmp->visited = 1;
				enqueue(queue, tmp->name);
			}*/
			if (links->room_link->visited == 0)
			{
				ft_printf("%s-%s\n", tmp->name, links->room_link->name);
				save_path(lemin, ft_strjoin(tmp->name, "-"), links->room_link->name);
				links->room_link->visited = 1;
				enqueue(queue, links->room_link->name);
			}
			links = links->next;
		}
	}
}
