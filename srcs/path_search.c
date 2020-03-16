/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:14 by gmolin            #+#    #+#             */
/*   Updated: 2020/03/16 13:18:43 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_room_pointers(t_lem *lem, int *room_pointers)
{
	int	i;

	i = 0;
	while (i < lem->room_amount)
	{
		room_pointers[i] = i;
		i++;
	}
}

t_list	*get_path(t_lem *lem, int *rooms_pointers)
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
	return (get);
}

t_list	*path_search(t_lem *lem_in, int *visited)
{
	t_queue	*queue;
	t_list	*connecting_rooms;
	t_list	*i;
	t_list	*path;
	int		**arr;
	int		room;
	int		end;
	// int		*visited;
	int		*room_pointers;

	// if (!(visited = (int*)ft_memalloc(sizeof(int) * lem_in->room_amount)))
	// 	ft_error("ERROR: allocate memory array visited");
	room_pointers = (int*)ft_memalloc(sizeof(int) * lem_in->room_amount);
	get_room_pointers(lem_in, room_pointers);
	arr = lem_in->links;
	end = lem_in->room_amount - 1;
	queue = create_queue();
	ft_enqueue(queue, new_list(0));
	while (queue->first != NULL)
	{
		room = pop_to_visit(queue);
		visited[room] = 1;
		connecting_rooms = get_connecting_rooms(room, visited, lem_in);
		i = connecting_rooms;
		while (i)
		{
			if (dereference((int*)i->content) != end || room_pointers[end] == end)
				room_pointers[dereference((int*)i->content)] = room;
			visited[dereference((int*)i->content)] = 1;
			ft_enqueue(queue, new_list(dereference((int*)i->content)));
			i = i->next;
		}
	}
	int a = 0;											/// from line 83 to 88: print room_pointers array
	while (a < lem_in->room_amount)                   
	{
		ft_printf("%i, ", room_pointers[a]);      
		a++;
	}
	if (visited[end] == 1)
	{
		path = get_path(lem_in, room_pointers);
		return (path);
	}
	return (NULL);
}

void	copy_path_visited(int *room_visited, int *path_visited, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		room_visited[i] = path_visited[i];
		i++;
	}
}

void	remove_visited(t_list *pa, int *path_visited, int room_amount)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = pa->content;
	while (tmp)
	{
		i = dereference((int*)tmp->content);
		if (i != 0 && i != room_amount - 1)
			path_visited[i] = 1;
		tmp = tmp->next;
	}
}

t_list	*get_path_list(t_lem *lem)
{
	t_queue	*paths;
	t_list	*paths_list;
	t_list	*pa;
	int		*room_visited;
	int		*path_visited;

	if (!(path_visited = (int*)ft_memalloc(sizeof(int) * lem->room_amount)))
		ft_error("ERROR: allocate memory path_array visited");
	if (!(room_visited = (int*)ft_memalloc(sizeof(int) * lem->room_amount)))
		ft_error("ERROR: allocate memory array visited");
	paths = create_queue();
	while ((pa = path_search(lem, room_visited)) != NULL)
	{
		remove_visited(pa, path_visited, lem->room_amount);
		copy_path_visited(room_visited, path_visited, lem->room_amount);
		ft_enqueue(paths, pa);
	}
	paths_list = paths->first;
	free(path_visited);
	free(room_visited);
	return (paths_list);
}
