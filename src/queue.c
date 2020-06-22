/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:40:41 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/17 15:30:23 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		is_empty(t_queue *queue)
{
	if (queue->rear == -1)
		return (1);
	return (0);
}

void	enqueue(t_queue *queue, char *value)
{
	if (queue->front == -1)
		queue->front = 0;
	queue->rear += 1;
	ft_strdel(&queue->items[queue->rear]);
	queue->items[queue->rear] = ft_strdup(value);
}

char	*dequeue(t_queue *q)
{
	char *item;

	if (is_empty(q))
		item = ft_strdup("-1");
	else
	{
		item = ft_strdup(q->items[q->front]);
		q->front++;
		if (q->front > q->rear)
		{
			q->front = -1;
			q->rear = -1;
		}
	}
	return (item);
}

t_queue	*init_queue(t_queue *queue, t_lemin *lemin)
{
	int		i;

	i = 0;
	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		exit_error();
	if (!(queue->items = (char**)malloc(sizeof(char*) * lemin->rooms + 1)))
		exit_error();
	while (i < lemin->rooms)
	{
		queue->items[i] = ft_strdup("0");
		i++;
	}
	queue->items[i] = NULL;
	queue->front = -1;
	queue->rear = -1;
	return (queue);
}

char	*init_str(t_lemin *lemin, char *str, char *str2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(str, str2);
	if (ft_strcmp(str2, lemin->end) == 0)
		return (tmp);
	tmp2 = ft_strjoin(tmp, "-");
	free(tmp);
	return (tmp2);
}
