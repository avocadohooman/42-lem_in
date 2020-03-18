/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:14 by gmolin            #+#    #+#             */
/*   Updated: 2020/03/18 18:14:10 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			dereference(int *p)
{
	return (*p);
}

static void	copy_path_visited(int *room_visited, int *path_visited, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		room_visited[i] = path_visited[i];
		i++;
	}
}

static void	remove_visited(t_list *pa, int *path_visited, int room_amount)
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

t_list		*get_path_list(t_lem *lem)
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
	while ((pa = path_search(lem, room_visited, lem->room_amount - 1)) != NULL)
	{
		remove_visited(pa, path_visited, lem->room_amount);
		copy_path_visited(room_visited, path_visited, lem->room_amount);
		ft_enqueue(paths, pa);
	}
	paths_list = paths->first;
	free(path_visited);
	free(room_visited);
	free(paths);
	return (paths_list);
}
