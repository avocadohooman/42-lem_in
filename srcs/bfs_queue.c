/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:10:39 by hopham            #+#    #+#             */
/*   Updated: 2020/02/26 09:31:11 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue			*create_queue(void)
{
	t_queue	*queue;

	if (!(queue= (t_queue*)ft_memalloc(sizeof(t_queue))))
		ft_error("ERROR: allocate memory queue");
	queue->first = NULL;
	return (queue);
}

void			pop_first_value(t_queue *queue)
{
	t_node 	*next_node;
	t_node	*tmp;

	if (!(queue) || !(queue->first))
		return ;
	tmp = queue->first;
	queue->pop = queue->first->content;
	next_node = queue->first->next;
	queue->first = next_node;
	free(tmp);
}

void			ft_enqueue(t_queue *queue, int content)
{
    t_node  *new;
    t_node  *tmp;
	
    if (!(queue))
        return ;
    if (!(new = (t_node*)ft_memalloc(sizeof(t_node))))
        ft_error("ERROR: allocate memory node");
    new->content = content;
    new->next = NULL;
    tmp = queue->first;
    if (!(tmp))
    {
        queue->first = new;
        return ;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}
