/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 11:03:01 by HoangPham         #+#    #+#             */
/*   Updated: 2020/06/30 16:00:21 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    set_to_n(int *set, int length, int n)
{
    int i;

    i = 0;
    while (i < length)
    {
        set[i] = n;
        i++;
    }
}

void    reset_queue(t_queue *q, int start, int end)
{
    q->queue[0] = start;
    q->visited[start] = 1;
    q->position = 1;
    if (end >= 0)
        q->visited[end] = 0;
}

void    initiate_queue(t_lem *lem_in, t_queue *q)
{
    int     i;
    
    q->len = lem_in->room_amount;
    if (!(q->queue = ft_memalloc(sizeof(int) * q->len)))
        ft_error("error memalloc q->queue");
    if (!(q->pre_room = ft_memalloc(sizeof(int) * q->len)))
        ft_error("error memalloc q->prev");
    if (!(q->visited = ft_memalloc(sizeof(int) * q->len)))
        ft_error("error memalloc q->visited");
    if (!(q->flow = ft_memalloc(sizeof(int) * q->len)))
        ft_error("error memalloc q->flow");
	i = 0;
    while (i < q->len)
    {
        if (!(q->flow[i] = ft_memalloc(sizeof(int) * q->len)))
            ft_error("error memalloc q->flow[i]");
        i++;
    } 
    set_to_n(q->queue, q->len, -1);
    set_to_n(q->pre_room, q->len, -1);
    reset_queue(q, 0, -1);
}

void    clear_queue(t_queue *q)
{
    set_to_n(q->pre_room, q->len, -1);
    set_to_n(q->queue, q->len, -1);
}
