/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:11:05 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/19 13:08:23 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	validate_link(t_room *rooms, char *name)
{
	t_list	*room_name;

	room_name = rooms->name_list;
	while (room_name)
	{
		if (!ft_strcmp(name, room_name->content))
			return ;
		room_name = room_name->next;
	}
	ft_error("ERROR: invalid links");
}

void		add_links(t_room *rooms, char *line)
{
	char	*from;
	char	*to;
	char	**split;

	ft_printf("%s\n", line);
	split = ft_strsplit(line, '-');
	from = split[0];
	to = split[1];
	validate_link(rooms, from);
	validate_link(rooms, to);
}
