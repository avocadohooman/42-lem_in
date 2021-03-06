/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:37:20 by HoangPham         #+#    #+#             */
/*   Updated: 2020/07/09 15:22:43 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Check if flow is negative
*/

static	int		find_neg_flow(t_queue *q, t_room *r)
{
	int i;

	i = 0;
	while (i < r->links_nb)
	{
		if (q->visited[r->links[i]] != 1 && q->flow[r->pos][r->links[i]] == -1)
		{
			q->queue[q->position] = r->links[i];
			q->position++;
			q->pre_room[r->links[i]] = r->pos;
			q->visited[r->links[i]] = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Find flow between 2 nodes, take negative flow (-1) first, if there is no
** negative flow then take flow 0.
*/

static	void	find_flow(t_queue *q, t_room *r, int prev_flow)
{
	int j;

	if (prev_flow == 0 && find_neg_flow(q, r))
		return ;
	j = 0;
	while (j < r->links_nb)
	{
		if (q->visited[r->links[j]] != 1 && q->flow[r->pos][r->links[j]] != 1)
		{
			q->queue[q->position] = r->links[j];
			q->position++;
			q->pre_room[r->links[j]] = r->pos;
			q->visited[r->links[j]] = 1;
		}
		j++;
	}
}

/*
** Starting at end, we travel back from end to start by the path we found
** by flow_travel(). During the travel we save flow as 1/-1, or 0/0 if that
** flow is already in another path found before.
*/

static	void	save_flow(t_lem *lem_in, t_queue *q)
{
	int src;
	int dst;

	src = lem_in->end_pos;
	if (q->pre_room[src] == lem_in->start_pos)
		return ;
	while (src != lem_in->start_pos)
	{
		dst = q->pre_room[src];
		if (q->flow[src][dst] == 0)
		{
			q->flow[src][dst] = -1;
			q->flow[dst][src] = 1;
		}
		else if (q->flow[src][dst] == 1 || q->flow[src][dst] == -1)
		{
			q->flow[src][dst] = 0;
			q->flow[dst][src] = 0;
		}
		src = dst;
	}
}

/*
** Starting at the start node, we explore the nodes in the queue, taking note
** of the flow from the parent to child node. Again, if at the end of the queue
** we have not visited end, we have not found a path and return 0.
*/

static	int		flow_travel(t_lem *lem_in, t_queue *q)
{
	int i;
	int node;
	int prev_flow;

	clear_queue(q);
	reset_queue(q, lem_in->start_pos, lem_in->end_pos);
	i = 0;
	prev_flow = 0;
	check_start_end(lem_in, q);
	while (i < q->len && q->visited[lem_in->end_pos] != 1 && q->queue[i] >= 0)
	{
		node = q->queue[i];
		if (i > 0)
			prev_flow = q->flow[q->pre_room[node]][node];
		find_flow(q, lem_in->rooms[node], prev_flow);
		i++;
	}
	if (q->pre_room[lem_in->end_pos] == -1 ||
		(q->pre_room[lem_in->end_pos] == lem_in->start_pos))
		return (0);
	return (1);
}

int				edmonds_karp(t_lem *lem_in, t_queue *q, t_path **p)
{
	t_path	*new_path;

	*p = ft_new_path(NULL, 0);
	while (flow_travel(lem_in, q) == 1)
	{
		new_path = ft_new_path(NULL, 0);
		save_flow(lem_in, q);
		set_to_n(q->visited, q->len, 0);
		reset_queue(q, lem_in->start_pos, lem_in->end_pos);
		save_path(lem_in, q, &new_path);
		if (new_path->max == 0)
			return (-1);
		lem_in->max_flow = new_path->max;
		if ((*p)->longest == 0 || (*p)->longest > new_path->longest)
		{
			free_path((*p));
			*p = new_path;
		}
		else
			free_path(new_path);
		clear_queue(q);
	}
	if ((*p)->path == NULL)
		return (0);
	return (1);
}
