/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_path_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:11:56 by hopham            #+#    #+#             */
/*   Updated: 2020/03/16 16:39:20 by gmolin           ###   ########.fr       */
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
			ft_lstadd(&node_list, new_list(i));
		i++;
	}
	return (node_list);
}