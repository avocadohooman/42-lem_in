/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:34:51 by hopham            #+#    #+#             */
/*   Updated: 2020/02/24 17:51:50 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room_to_array(t_lem *lem_in)
{
	t_list	*name_list;
	int		i;
	int		k;

	name_list = lem_in->name_list;
	room_malloc(lem_in);
	i = 1;
	k = 1;
	while (name_list)
	{
		if (!ft_strcmp((char*)name_list->content, lem_in->start))
		{
			lem_in->rooms[0]->name = lem_in->start;
		}
		else if (!ft_strcmp((char*)name_list->content, lem_in->end))
		{
			lem_in->rooms[lem_in->room_amount - 1]->name = lem_in->end;
			lem_in->rooms[lem_in->room_amount - 1]->pos = lem_in->room_amount - 1;
		}
		else
		{
			lem_in->rooms[i]->name = name_list->content;
			lem_in->rooms[i]->pos = i;
			i++;
		}
		name_list = name_list->next;
	}
}


void	add_links_to_arrays(t_lem *lem_in)
{
	int		i;
	int		j;
	t_link 	*tmp2;
	
	links_malloc(lem_in);
	j = 0;
	tmp2 = lem_in->link_list;
	while (j < lem_in->room_amount)
	{
		while (lem_in->link_list)
		{
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
			lem_in->link_list = lem_in->link_list->next;
		}
		lem_in->link_list = tmp2;
		j++;
	}
	int  k = 0;
	i = 0;
	while (i < lem_in->room_amount)
	{
		k = 0;
		while (k < lem_in->room_amount)
		{
			ft_printf("%d ", lem_in->links[i][k]);
			k++;
		}
		ft_printf("\n");
		i++;
	}
}
