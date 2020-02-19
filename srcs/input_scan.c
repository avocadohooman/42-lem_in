/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:27:13 by hopham            #+#    #+#             */
/*   Updated: 2020/02/19 10:17:17 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		scanning_links(char **line, t_room *room)
{
	if (ft_strstr(*line, "-"))
		ft_printf("%s\n", line);
	room->c_start = room->c_start;
	ft_strdel(line);
}

static void		scanning_rooms(char **line, t_room *room)
{
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

int				input_scan(t_room *room)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		scanning_rooms(&line, room);
		scanning_links(&line, room);
	}
	if (room->c_start!= 1 || room->c_end != 1)
		ft_error("ERROR: Duplicates.");
	return (0);
}

// int				input_scan(t_room *room)
// {
// 	char	*line;
// 	int		start;
// 	int		end;

// 	start = 0;
// 	end = 0;
// 	while (get_next_line(0, &line) > 0)
// 	{
// 		scanning_rooms(&line)
// 		if (ft_strcmp("##start", line) == 0)
// 		{
// 			start++;
// 			get_next_line(0, &line);
// 			(start == 1) ? add_rooms("start", &line, room) : 0;
// 		}
// 		else if (ft_strcmp("##end", line) == 0)
// 		{
// 			end++;
// 			get_next_line(0, &line);
// 			(end == 1) ? add_rooms("end", &line, room) : 0;
// 		}
// 		else if (line[0] == '#' && line[1] != '#')
// 			ft_strdel(&line);
// 		else
// 			add_rooms("room", &line, room);
// 		ft_strdel(&line);
// 	}
// 	if (start != 1 || end != 1)
// 		ft_error("ERROR: Duplicates.");
// 	return (0);
// }
