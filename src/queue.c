/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:40:41 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/09/30 15:41:22 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		is_empty(t_queue *queue)
{
	if (queue->rear == -1)
		return (1);
	return (0);
}

void	enqueue(t_queue *queue, int value)
{
	int		i;

	i = value;
	if (queue->front == -1)
		queue->front = 0;
	queue->rear += 1;
	queue->items[queue->rear] = i;
}

int		dequeue(t_queue *q)
{
	int		item;

	if (is_empty(q))
		item = -1;
	else
	{
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear)
		{
			q->front = -1;
			q->rear = -1;
		}
	}
	return (item);
}

t_queue	*init_queue(t_lemin *lemin)
{
	t_queue	*queue;
	int		i;

	i = 0;
	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		exit_error();
	if (!(queue->items = (int*)malloc(sizeof(int) * lemin->rooms)))
		exit_error();
	queue->front = -1;
	queue->rear = -1;
	return (queue);
}
