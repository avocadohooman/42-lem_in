/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:11:56 by hopham            #+#    #+#             */
/*   Updated: 2020/03/17 11:45:10 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list			*new_list(int i)
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

static t_list	*get_connecting_rooms(int visiting, int *visited, t_lem *lem)
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
			ft_lstadd(&node_list, new_list(i));
		i++;
	}
	return (node_list);
}

static int		*get_room_pointers(t_lem *lem)
{
	int	i;
	int	*room_pointers;

	i = 0;
	room_pointers = (int*)ft_memalloc(sizeof(int) * lem->room_amount);
	while (i < lem->room_amount)
	{
		room_pointers[i] = i;
		i++;
	}
	return (room_pointers);
}

static t_list	*get_path(t_lem *lem, int *rooms_pointers)
{
	t_list	*path;
	t_list	*get;
	int		i;
	int		end;
	int		length;

	path = NULL;
	end = lem->room_amount - 1;
	i = end;
	length = 0;
	while (rooms_pointers[i] != i)
	{
		ft_lstadd(&path, new_list(i));
		i = rooms_pointers[i];
		length++;
	}
	if (i != end)
		ft_lstadd(&path, new_list(i));
	get = (t_list*)ft_memalloc(sizeof(t_list));
	get->content = path;
	get->content_size = length - 1;
	get->next = NULL;
	free(rooms_pointers);
	return (get);
}

t_list	*path_search(t_lem *lem_in, int *visited, int end)
{
	t_queue	*queue;
	t_list	*i;
	int		room;
	int		*room_pointers;

	room_pointers = get_room_pointers(lem_in);
	queue = create_queue();
	ft_enqueue(queue, new_list(0));
	while (queue->first != NULL)
	{
		room = pop_to_visit(queue);
		visited[room] = 1;
		i = get_connecting_rooms(room, visited, lem_in);
		while (i)
		{
			if (dereference((int*)i->content) != end || room_pointers[end] == end)
				room_pointers[dereference((int*)i->content)] = room;
			visited[dereference((int*)i->content)] = 1;
			ft_enqueue(queue, new_list(dereference((int*)i->content)));
			i = i->next;
		}
	}
	if (visited[end] == 1)
		return (get_path(lem_in, room_pointers));
	return (NULL);
}
