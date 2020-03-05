/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_path_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:11:56 by hopham            #+#    #+#             */
/*   Updated: 2020/03/03 13:29:40 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		dereference(int *p)
{
	return (*p);
}

void	visit(int visiting, t_lem *lem)
{
	lem->links[visiting][visiting] = lem->links[visiting][visiting] | 1;
}

t_list	*new_list(int i)
{
	t_list	*tmp;
	int		*n;

	tmp = (t_list*)ft_memalloc(sizeof(t_list));
	n = (int*)ft_memalloc(sizeof(int));
	*n = i;
	tmp->content = n;
	tmp->content_size = 0;
	tmp->next = NULL;
	return (tmp);
}

t_list	*get_connecting_rooms(int visiting, int *visited, t_lem *lem)
{
	t_list	*node_list;
	int		i;
	int		end;

	end = lem->room_amount - 1;
	if (visiting == end)
		return (NULL);
	node_list = NULL;
	i = 0;
	while (i < lem->room_amount)
	{
		if (lem->links[visiting][i] == 1 && visited[i] == 0)
		{
			// lem->links[i][i] = lem->links[i][i] | 1;
			ft_lstadd(&node_list, new_list(i));
		}
		i++;
	}
	return (node_list);
}

// t_list	*get_path(t_lem *lem, int end, int *room_pointers)
// {
// 	t_list	*path;
// 	t_list	*wrapper;
// 	int		i;
// 	int		length;

// 	path = NULL;
// 	i = end;
// 	length = 0;
// 	while (room_pointers[i] != i)
// 	{
// 		lem->links[i][i] = lem->links[i][i] | 2;
// 		ft_lstadd(&path, new_list(i));
// 		i = room_pointers[i];
// 		length++;
// 	}
// 	if (i != end)
// 		ft_lstadd(&path, new_list(i));
// 	length = i != end ? length + 1 : length;
// 	if (path == NULL)
// 		return (NULL);
// 	wrapper = (t_list*)ft_memalloc(sizeof(t_list));
// 	wrapper->content = path;
// 	wrapper->content_size = length - 1;
// 	wrapper->next = NULL;
// 	return (wrapper);
// }

// void	push(t_queue *queue, t_list *ta)
// {
// 	t_list	*tmp;

// 	ta->next = NULL;
// 	tmp = queue->first;
// 	if (queue->first == NULL)
// 		queue->first = ta;
// 	else
// 	{
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = ta;
// 	}
// }

// t_list	*bfs_get_path(t_lem *lem_in)
// {
// 	t_list	*path;
// 	t_list	*i;
// 	t_list	*connecting_rooms;
// 	t_queue	*queue;
// 	int		room;
// 	int		end;
// 	int		*room_pointers;

// 	room_pointers = (int*)ft_memalloc(sizeof(int) * lem_in->room_amount);
// 	get_room_pointers(room_pointers, lem_in);
// 	end = lem_in->room_amount - 1;
// 	queue = create_queue();
// 	push(queue, new_list(0));
// 	while (queue->first != NULL)
// 	{
// 		pop_first_value(queue);
// 		room = queue->pop;
// 		connecting_rooms = get_connecting_rooms(room, end, lem_in);
// 		i = connecting_rooms;
// 		while (i)
// 		{
// 			if (dereference((int*)i->content) != end || room_pointers[end] == end)
// 				room_pointers[dereference((int*)i->content)] = room;
// 			visit(dereference((int*)i->content), lem_in);
// 			push(queue, new_list(dereference((int*)i->content)));
// 			i = i->next;
// 		}
// 	}
// 	path = get_path(lem_in, end, room_pointers);
// 	return (path);
// }

// void	remove_visited(t_lem *lem, int start)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < lem->room_amount)
// 	{
// 		if (i != start)
// 			lem->links[i][i] = lem->links[i][i] & 2;
// 		i++;
// 	}
// }

// t_list	*path_search(t_lem *lem_in)
// {
// 	t_queue	*path;
// 	t_list	*path_list;
// 	t_list	*ta;

// 	lem_in->links[0][0] = 1;
// 	path = create_queue();
// 	while ((ta = bfs_get_path(lem_in)))
// 	{
// 		push(path, ta);
// 		remove_visited(lem_in, 0);
// 	}
// 	path_list = path->first;
// 	return (path_list);
// }
