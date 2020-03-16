/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:34:51 by hopham            #+#    #+#             */
/*   Updated: 2020/03/16 17:43:38 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			lem->rooms[0]->name = lem->start;
		}
		else if (!ft_strcmp((char*)name_list->content, lem->end))
		{
			lem->rooms[lem->room_amount - 1]->name = lem->end;
			lem->rooms[lem->room_amount - 1]->pos = lem->room_amount - 1;
		}
		else
		{
			lem->rooms[i]->name = name_list->content;
			lem->rooms[i]->pos = i;
			i++;
		}
		name_list = name_list->next;
	}
}

static void		check_connection(t_lem *lem_in, int j)
{
	int i;

	i = 0;
	if (!ft_strcmp(lem_in->link_list->from, lem_in->rooms[j]->name))
	{
		while (ft_strcmp(lem_in->link_list->to, lem_in->rooms[i]->name))
			i++;
		lem_in->links[j][lem_in->rooms[i]->pos] = 1;
	}
	i = 0;
	if (!ft_strcmp(lem_in->link_list->to, lem_in->rooms[j]->name))
	{
		while (ft_strcmp(lem_in->link_list->from, lem_in->rooms[i]->name))
			i++;
		lem_in->links[j][lem_in->rooms[i]->pos] = 1;
	}
}

void			add_links_to_arrays(t_lem *lem_in)
{
	int		j;
	t_link	*tmp;

	links_malloc(lem_in);
	j = 0;
	tmp = lem_in->link_list;
	while (j < lem_in->room_amount)
	{
		while (lem_in->link_list)
		{
			check_connection(lem_in, j);
			lem_in->link_list = lem_in->link_list->next;
		}
		lem_in->link_list = tmp;
		j++;
	}
}
