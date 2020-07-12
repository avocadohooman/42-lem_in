/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:27:13 by hopham            #+#    #+#             */
/*   Updated: 2020/07/12 14:33:24 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		scanning_links(char **line, t_lem *room)
{
	if (*line[0] == '#' && *line[1] != '#')
	{
		ft_printf("%s\n", *line);
		ft_strdel(line);
		return ;
	}
	add_links(room, *line);
	ft_strdel(line);
}

static int		free_and_check_line(char **line)
{
	free(*line);
	get_next_line(0, line);
	if (ft_strlen(*line) == 0)
		return (0);
	return (1);
}

static int		scanning_rooms(char **line, t_lem *room, int check)
{
	if (ft_strcmp("##start", *line) == 0 && check == 0)
	{
		room->c_start++;
		if (!free_and_check_line(line))
			return (0);
		(room->c_start == 1) ? add_rooms("start", line, room) : 0;
	}
	else if (ft_strcmp("##end", *line) == 0 && check == 0)
	{
		room->c_end++;
		if (!free_and_check_line(line))
			return (0);
		(room->c_end == 1) ? add_rooms("end", line, room) : 0;
	}
	else if (*line[0] == '#' && *line[1] != '#')
	{
		ft_printf("%s\n", *line);
		ft_strdel(line);
		return (2);
	}
	else if (check == 0)
		add_rooms("room", line, room);
	ft_strdel(line);
	return (1);
}

int				input_scan(t_lem *room)
{
	char	*line;
	int		check;

	check = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strstr(line, "-") && ft_strlen(line) > 0)
		{
			if (ft_strstr(line, "##end") || ft_strstr(line, "##start"))
				ft_printf("%s\n", line);
			if (scanning_rooms(&line, room, check) == 0)
				break ;
		}
		else if (ft_strstr(line, "-"))
		{
			scanning_links(&line, room);
			check = 1;
		}
		else if (ft_strlen(line) == 0)
			break ;
	}
	if (room->c_start != 1 || room->c_end != 1)
		ft_error("ERROR: No start or end room.");
	return (0);
}
