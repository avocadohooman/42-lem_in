/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:14:39 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/06 21:46:17 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_weights(t_lem *lem_in)
{
	int i;

	i = 0;
	while (i < lem_in->room_amount)
	{
		lem_in->rooms[i]->weight = __INT_MAX__;
		i++;
	}
	lem_in->rooms[0]->weight = 0;
}

static int	compare_weights(t_room *next, t_room *current, t_queue *q)
{
	int i;

	if (q->flow[current->pos][next->pos] == 1)
		return (0);
	if (q->flow[current->pos][next->pos] == -1)
		i = current->weight - 1;
	else
		i = current->weight + 1;
	if (i < next->weight && next->weight != __INT_MAX__)
	{
		next->weight = i;
		return (1);
	}
	return (0);
}

static int	check_loops(t_room *current, t_room *next, t_queue *q, t_lem *lem_in)
{
	int i;

	i = q->pre_room[current->pos];
	while(i != lem_in->end_pos && i != lem_in->start_pos)
	{
		if (i == next->pos)
			return (1);
		if (i == current->pos)
			return (1);
		if (i == q->pre_room[next->pos])
			return (1);
		i = q->pre_room[i];
	}
	return (0);
}


int		check_weights(t_room *next, t_room *current, t_queue *q, t_lem *lem_in)
{
	if (next->pos == lem_in->start_pos || current->pos == lem_in->start_pos || next->pos == lem_in->start_pos)
		return (0);
	if (check_loops(current, next, q, lem_in) == 1)
		return (0);
	if (compare_weights(next, current, q) == 0)
		return (0);
	if ((lem_in->rooms[q->pre_room[next->pos]]->pos != lem_in->start_pos) && (check_loops(lem_in->rooms[q->pre_room[next->pos]], next, q, lem_in) == 0 &&
		(compare_weights(lem_in->rooms[q->pre_room[next->pos]], next, q) == 1)))
		q->pre_room[q->pre_room[next->pos]] = next->pos;
	q->pre_room[next->pos] = current->pos;
	return (1);
}
