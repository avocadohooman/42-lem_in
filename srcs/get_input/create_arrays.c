/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:34:51 by hopham            #+#    #+#             */
/*   Updated: 2020/07/10 18:04:00 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdbool.h>

static	void	initiate_end_room(t_lem *lem, char *end)
{
	lem->rooms[lem->room_amount - 1]->name = end;
	lem->rooms[lem->room_amount - 1]->pos = lem->room_amount - 1;
	lem->end_pos = lem->room_amount - 1;
	lem->rooms[lem->room_amount - 1]->empty = -1;
}

void			add_room_to_array(t_lem *lem)
{
	t_list	*name_list;
	int		i;

	name_list = lem->name_list;
	room_malloc(lem);
	i = 1;
	while (name_list)
	{
		if (!ft_strcmp((char*)name_list->content, lem->start))
		{
			lem->rooms[0]->name = (char*)name_list->content;
			lem->rooms[0]->empty = -1;
			lem->start_pos = 0;
		}
		else if (!ft_strcmp((char*)name_list->content, lem->end))
			initiate_end_room(lem, (char*)name_list->content);
		else
		{
			lem->rooms[i]->name = name_list->content;
			lem->rooms[i]->pos = i;
			lem->rooms[i]->empty = -1;
			i++;
		}
		name_list = name_list->next;
	}
}

static void		mark_connection(t_lem *lem_in, int i, int j, int *a)
{
	if (lem_in->links[j][lem_in->rooms[i]->pos] != 1)
	{
		lem_in->links[j][lem_in->rooms[i]->pos] = 1;
		lem_in->rooms[j]->links_nb++;
		lem_in->rooms[j]->links[*a] = lem_in->rooms[i]->pos;
		(*a)++;
	}
}

static void		check_connection(t_lem *lem_in, int j, int *a)
{
	int i;

	i = 0;
	if (!ft_strcmp(lem_in->link_list->from, lem_in->rooms[j]->name))
	{
		while (ft_strcmp(lem_in->link_list->to, lem_in->rooms[i]->name))
			i++;
		mark_connection(lem_in, i, j, a);
	}
	i = 0;
	if (!ft_strcmp(lem_in->link_list->to, lem_in->rooms[j]->name))
	{
		while (ft_strcmp(lem_in->link_list->from, lem_in->rooms[i]->name))
			i++;
		mark_connection(lem_in, i, j, a);
	}
}

void			add_links_to_arrays(t_lem *lem_in)
{
	int		j;
	int		a;
	t_link	*tmp;

	links_malloc(lem_in);
	j = 0;
	tmp = lem_in->link_list;
	while (j < lem_in->room_amount)
	{
		a = 0;
		while (lem_in->link_list)
		{
			check_connection(lem_in, j, &a);
			lem_in->link_list = lem_in->link_list->next;
		}
		lem_in->link_list = tmp;
		j++;
	}
}
