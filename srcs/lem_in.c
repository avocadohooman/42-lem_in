/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:04 by hopham            #+#    #+#             */
/*   Updated: 2020/02/18 16:26:43 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ants(void)
{
	char	*line;
	int		ant_numbers;

	get_next_line(0, &line);
	ant_numbers = ft_atoi(line);
	ft_strdel(&line);
	ft_printf("%d\n", ant_numbers);
	if (ant_numbers <= 0 || ant_numbers > INT_MAX)
		ft_error("ant_numbers is not valid"); 
	return (ant_numbers);
}

static void testing_env(t_ants *ants, t_room *room)
{
	ft_printf("Amount of ants: %d\nStarting room: %s\nEnding room: %s\n", ants->amount, room->start, room->end);
	while (room->name_list)
	{
		ft_printf("%s\n", room->name_list->content);
		room->name_list = room->name_list->next;
	}
}

int			main(void)
{
	t_ants 	*ants;
	t_room 	*room;

	if (!(ants = (t_ants*)ft_memalloc(sizeof(t_ants))))
		return (0);
	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (0);
	initiate_structs(ants, room);
	ants->amount = get_ants();
	input_scan(room);
	testing_env(ants, room);
	return (0);
}
