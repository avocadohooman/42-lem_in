/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:27:13 by hopham            #+#    #+#             */
/*   Updated: 2020/02/18 16:06:27 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		input_scan(t_room *room)
{
	char	*line;
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp("##start", line) == 0)
		{
			start++;
			get_next_line(0, &line);
			(start == 1) ? add_rooms("start", &line, room) : 0;
		}
		else if (ft_strcmp("##end", line) == 0)
		{
			end++;
			get_next_line(0, &line);
			(end == 1) ? add_rooms("end", &line, room) : 0;
		}
		else
			add_rooms("room", &line, room);
		ft_strdel(&line);
	}
	if (start != 1 || end != 1)
		ft_error("ERROR: Duplicates.");
	return (0);
}
