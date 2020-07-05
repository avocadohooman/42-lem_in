/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:11:56 by hopham            #+#    #+#             */
/*   Updated: 2020/07/05 16:31:12 by gmolin           ###   ########.fr       */
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
	t_list	*tmp;

	end = lem->room_amount - 1;
	if (visiting == end)
		return (NULL);
	node_list = NULL;
	i = 0;
	while (i < lem->room_amount)
	{
		if (lem->links[visiting][i] == 1 && visited[i] == 0)
		{
			tmp = new_list(i);
			ft_lstadd(&node_list, tmp);
		}
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
	get = NULL;
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

t_list			*path_search(t_lem *lem, int *visited, int end)
{
	t_queue	*queue;
	t_list	*i;

	lem->room_p = get_room_pointers(lem);
	queue = create_queue();
	ft_enqueue(queue, new_list(0));
	while (queue->first != NULL)
	{
		lem->room = pop_to_visit(queue);
		visited[lem->room] = 1;
		i = get_connecting_rooms(lem->room, visited, lem);
		while (i)
		{
			if (dereference((int*)i->content) != end || lem->room_p[end] == end)
				lem->room_p[dereference((int*)i->content)] = lem->room;
			visited[dereference((int*)i->content)] = 1;
			ft_enqueue(queue, new_list(dereference((int*)i->content)));
			i = freeing(i);
		}
	}
	free(queue);
	if (visited[end] == 1)
		return (get_path(lem, lem->room_p));
	free(lem->room_p);
	return (NULL);
}
