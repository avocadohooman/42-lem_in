/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:01:04 by HoangPham         #+#    #+#             */
/*   Updated: 2020/06/28 18:14:16 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Count steps between start and end.
*/

static int  count_steps(t_queue *q, int start, int end)
{
    int steps;

    steps = 0;
    while (end != start)
    {
        end = q->pre_room[end];
        steps++;
    }
    return (steps);
}

/*
** After bfs travel to end room, we need to travel back from end to start
** to save the path found.  
*/

static int  *rev_path(t_lem *lem_in, t_queue *q, int steps)
{
    int *rev_path;
    int i;
    int pos;

    i = 0;
    pos = lem_in->start_pos;
    if (!(rev_path = ft_memalloc((sizeof(int) * (steps + 1)))))
        ft_error("Error memalloc rev_path");
    rev_path[steps] = pos;
    while (i <= steps)
    {
        rev_path[steps - i] = pos;
        pos = q->pre_room[pos];
        i++;
    }
    return (rev_path);
}

/*
** When we use our path finding functions we use 1 to mark
** that we have visited the node during that iteration of
** path finding. Here we mark the path found with the number 2
** in order to differenciate between nodes visited, and nodes
** used in other paths. We also reset our queue and others visited
** nodes not in the path found, to prepare for the next bfs travel.
*/

static void mark_path(t_lem *lem_in, t_queue *q)
{
    int path;
    int j;

    path = q->pre_room[lem_in->end_pos];
    while (path != lem_in->start_pos)
    {
        q->visited[path] = 2;
        path = q->pre_room[path];
    }
    j = 0;
    while (j < q->len)
    {
        q->pre_room[j] = -1;
        q->queue[j] = -1;
        if (q->visited[j] == 1)
            q->visited[j] = 0;
        j++;
    }
}

/*
** Using bfs to find all paths with flow = 1, save th
*/

void        save_path(t_lem *lem_in, t_queue *q, t_path **path_list)
{
    int     *path;
    int     steps;
    t_path  *new;
    int     i;

    i = 0;
    while (bfs(lem_in, q) == 1)
    {
        steps = count_steps(q, lem_in->start_pos, lem_in->end_pos);
        path = rev_path(lem_in, q, steps);
        mark_path(lem_in, q);
        new = ft_new_path(path, steps + 1);
        ft_memdel((void*)&path);
        ft_add_path(path_list, new);
        i++;
    }
    (*path_list)->max = i;
}
