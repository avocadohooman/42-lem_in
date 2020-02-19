/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:14 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/19 17:32:30 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		path_search(t_room *room)
{
	while (room->link_list)
	{
		if (!ft_strcmp(room->link_list->from, room->start))
			ft_printf("Connection : %s\n", room->link_list->to);
		else if (!ft_strcmp(room->link_list->to, room->start))
			ft_printf("Connection : %s\n", room->link_list->from);
		room->link_list = room->link_list->next;
	}
}