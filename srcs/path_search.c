/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:14 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/20 10:25:34 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			path_search(t_room *room, char *find)
{
	t_link 	*tmp;
	char 	*path;
	char	*tmp_path;

	tmp_path = malloc(sizeof(char) * 4096);
	path = malloc(sizeof(char) * 4096);
	tmp = room->link_list;
	while (room->link_list && (room->link_list->to != room->end || room->link_list->from != room->end))
	{
		if (!ft_strcmp(room->link_list->from, find) && room->link_list->visited == 0)
		{
			ft_printf("%s - connection : %s\n", find, room->link_list->to);
			tmp_path = ft_strjoin(find, room->link_list->to);
			path = ft_strjoin(path, tmp_path);
			ft_printf("path: %s\n\n", path);
			room->link_list->visited = 1;
			find = room->link_list->to;
			room->link_list = tmp;
		}
		else if (!ft_strcmp(room->link_list->to, find) && room->link_list->visited == 0)
		{
			ft_printf("%s - connection : %s\n", find, room->link_list->to);
			room->link_list->visited = 1;
			find = room->link_list->to;
			room->link_list = tmp;
		}
		room->link_list = room->link_list->next;
	}
}
