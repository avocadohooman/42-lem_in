/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:10:39 by hopham            #+#    #+#             */
/*   Updated: 2020/03/17 11:42:00 by HoangPham        ###   ########.fr       */
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

static t_list	*pop_first_value(t_queue *queue)
{
	t_list	*tmp;

	if (!(queue->first))
		return (NULL);
	tmp = queue->first;
	queue->first = queue->first->next;
	return (tmp);
}

int				pop_to_visit(t_queue *to_visit)
{
	t_list	*tmp;
	int		room;

	tmp = pop_first_value(to_visit);
	room = dereference((int*)tmp->content);
	free(tmp->content);
	free(tmp);
	return (room);
}

void			ft_enqueue(t_queue *queue, t_list *new)
{
	t_list	*tmp;

    new->next = NULL;
	tmp = NULL;
	if (!queue->first)
        queue->first = new;
    else
	{
		tmp = queue->first;
		while (tmp->next)
        	tmp = tmp->next;
    	tmp->next = new;
	}
}

