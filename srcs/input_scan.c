/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:27:13 by hopham            #+#    #+#             */
/*   Updated: 2020/03/16 20:19:37 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		scanning_links(char **line, t_lem *room)
{
	add_links(room, *line);
	ft_strdel(line);
}

static void		scanning_rooms(char **line, t_lem *room)
{
	(ft_strstr(*line, "##")) ? ft_printf("%s\n", *line) : 0;
	if (ft_strcmp("##start", *line) == 0)
	{
		room->c_start++;
		get_next_line(0, line);
		(room->c_start == 1) ? add_rooms("start", line, room) : 0;
	}
	else if (ft_strcmp("##end", *line) == 0)
	{
		room->c_end++;
		get_next_line(0, line);
		(room->c_end == 1) ? add_rooms("end", line, room) : 0;
	}
	else if (*line[0] == '#' && *line[1] != '#')
	{
		ft_strdel(line);
		return ;
	}
	else
		add_rooms("room", line, room);
	ft_strdel(line);
}

int				input_scan(t_lem *room)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strstr(line, "-"))
			scanning_rooms(&line, room);
		else if (ft_strstr(line, "-"))
			scanning_links(&line, room);
	}
	if (room->c_start!= 1 || room->c_end != 1)
		ft_error("ERROR: No start or end room.");
	return (0);
}
