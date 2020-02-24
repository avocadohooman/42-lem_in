/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:04 by hopham            #+#    #+#             */
/*   Updated: 2020/02/24 12:42:03 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ants(void)
{
	char		*line;
	int			ant_numbers;
	size_t		i;

	i = 0;
	get_next_line(0, &line);
	while (i < ft_strlen(line))
	{
		if (!ft_isdigit(line[i]))
			ft_error("invalid input");
		i++;
	}
	ant_numbers = ft_atoi(line);
	ft_strdel(&line);
	ft_printf("%d\n", ant_numbers);
	if (ant_numbers <= 0 || ant_numbers > INT_MAX)
		ft_error("ant_numbers is not valid"); 
	return (ant_numbers);
}

// static void testing_env(t_ants *ants, t_room *room)
// {
// 	ft_printf("\nAmount of ants: %d\nStarting room: %s\nEnding room: %s\n", ants->amount, room->start, room->end);
// 	while (room->link_list)
// 	{
// 		ft_printf("from: %s\nto: %s\n", room->link_list->from, room->link_list->to);
// 		room->link_list = room->link_list->next;
// 	}
// }

int			main(void)
{
	t_ants 	*ants;
	t_lem 	*room;

	if (!(ants = (t_ants*)ft_memalloc(sizeof(t_ants))))
		return (0);
	if (!(room = (t_lem*)ft_memalloc(sizeof(t_lem))))
		return (0);
	initiate_structs(ants, room);
	ants->amount = get_ants();
	input_scan(room);
	path_search(room, room->start);
	// testing_env(ants, room);
	return (0);
}
