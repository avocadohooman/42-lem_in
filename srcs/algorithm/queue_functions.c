/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:03:01 by HoangPham         #+#    #+#             */
/*   Updated: 2020/07/10 16:33:58 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_to_n(int *set, int length, int n)
{
	int i;

	i = 0;
	while (i < length)
	{
		set[i] = n;
		i++;
	}
}

void	reset_queue(t_queue *q, int start, int end)
{
	q->queue[0] = start;
	q->visited[start] = 1;
	q->position = 1;
	if (end >= 0)
		q->visited[end] = 0;
}

void	initiate_queue(t_lem *lem_in, t_queue *q)
{
	int	i;
	int	j;

	q->len = lem_in->room_amount;
	if (!(q->queue = (int*)ft_memalloc(sizeof(int) * q->len)))
		ft_error("error memalloc q->queue");
	if (!(q->pre_room = (int*)ft_memalloc(sizeof(int) * q->len)))
		ft_error("error memalloc q->prev");
	if (!(q->visited = (int*)ft_memalloc(sizeof(int) * q->len)))
		ft_error("error memalloc q->visited");
	if (!(q->flow = (int**)ft_memalloc(sizeof(int*) * q->len)))
		ft_error("error memalloc q->flow");
	i = -1;
	while (++i < q->len)
	{
		j = -1;
		if (!(q->flow[i] = (int*)ft_memalloc(sizeof(int) * q->len)))
			ft_error("error memalloc q->flow[i]");
		while (++j < q->len)
			q->flow[i][j] = 0;
	}
	set_to_n(q->queue, q->len, -1);
	set_to_n(q->pre_room, q->len, -1);
	reset_queue(q, 0, -1);
}

void	clear_queue(t_queue *q)
{
	set_to_n(q->pre_room, q->len, -1);
	set_to_n(q->queue, q->len, -1);
}

void	free_queue(t_queue *q)
{
	int	i;

	i = 0;
	while (i < q->len)
	{
		ft_memdel((void*)&q->flow[i]);
		i++;
	}
	if (q->flow != NULL)
		free(q->flow);
	if (q->pre_room != NULL)
		free(q->pre_room);
	if (q->queue != NULL)
		free(q->queue);
	if (q->visited != NULL)
		free(q->visited);
	ft_memdel((void*)&q);
}
