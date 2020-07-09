/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:23:33 by HoangPham         #+#    #+#             */
/*   Updated: 2020/07/09 12:25:03 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			check_start_end(t_lem *lem_in, t_queue *q)
{
	int	i;

	i = 0;
	while (i != lem_in->rooms[lem_in->start_pos]->links_nb)
	{
		if (lem_in->rooms[lem_in->start_pos]->links[i] == lem_in->end_pos)
		{
			q->flow[lem_in->start_pos][lem_in->end_pos] = 1;
			q->flow[lem_in->end_pos][lem_in->start_pos] = -1;
			q->pre_room[lem_in->end_pos] = lem_in->start_pos;
		}
		i++;
	}
}

/*
** This finds linked or (neighbouring) nodes and adds them to the queue
** if they are accessible (flow of 1) and they have not already been
** visited.
*/

static void		find_neighbors(t_queue *q, t_room *r)
{
	int j;

	j = 0;
	while (j < r->links_nb)
	{
		if (q->visited[r->links[j]] == 0 && q->flow[r->pos][r->links[j]] == 1)
		{
			q->queue[q->position] = r->links[j];
			q->position++;
			q->pre_room[r->links[j]] = r->pos;
			q->visited[r->links[j]] = 1;
		}
		j++;
	}
}

int				bfs(t_lem *lem_in, t_queue *q)
{
	int i;
	int node;

	i = 0;
	set_to_n(q->queue, q->len, -1);
	reset_queue(q, lem_in->start_pos, lem_in->end_pos);
	while (i < q->len && q->visited[lem_in->end_pos] != 1 && q->queue[i] >= 0)
	{
		node = q->queue[i];
		find_neighbors(q, lem_in->rooms[node]);
		i++;
	}
	if (q->visited[lem_in->end_pos] != 1)
		return (0);
	if (q->flow[lem_in->start_pos][lem_in->end_pos] == 1
		&& q->pre_room[lem_in->end_pos] == lem_in->start_pos)
		q->flow[lem_in->start_pos][lem_in->end_pos] = 0;
	return (1);
}
