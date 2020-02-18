/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:10:08 by hopham            #+#    #+#             */
/*   Updated: 2020/02/18 17:00:49 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	validate(t_room *room)
{
	int i;
	t_list *tmp;

	tmp = room->name_list;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, room->name))
			i++;
		if (i > 1 || room->name[0] == 'L' || room->name[0] == '#')
			ft_error("ERROR: Duplicates");
		tmp = tmp->next;
	}
}

void	add_rooms(char *type, char **line, t_room *room)
{
	char	**strsplit;

	strsplit = ft_strsplit(*line, ' ');
	// if (strsplit[0][0] != 'L' && strsplit[0][0] != '#')
	// {
		if (!ft_strcmp(type, "start"))
			room->start = strsplit[0];
		else if (!ft_strcmp(type, "end"))
			room->end = strsplit[0];
		room->name = strsplit[0];
		if (room->name_list)
			ft_lstadd_end(&room->name_list, ft_lstnew_str(room->name));
		else
			room->name_list = ft_lstnew_str(room->name);
	// }
	ft_strdel(line);
	validate(room);
}
