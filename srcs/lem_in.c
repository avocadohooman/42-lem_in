/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:04 by hopham            #+#    #+#             */
/*   Updated: 2020/02/24 17:50:46 by hopham           ###   ########.fr       */
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

static void testing_env(t_ants *ants, t_lem *lem_in)
{
	int i;

	i = 0;
	ft_printf("\nAmount of ants: %d\nStarting room: %s\nEnding room: %s\n", ants->amount, lem_in->start, lem_in->end);
	while (lem_in->link_list && i < lem_in->room_amount)
	{
		ft_printf("room name: %s\nroom index: %d\n", lem_in->rooms[i]->name, lem_in->rooms[i]->pos);
		lem_in->link_list = lem_in->link_list->next;
		i++;
	}
}

int			main(void)
{
	t_ants 	*ants;
	t_lem 	*lem_in;

	if (!(ants = (t_ants*)ft_memalloc(sizeof(t_ants))))
		return (0);
	if (!(lem_in = (t_lem*)ft_memalloc(sizeof(t_lem))))
		return (0);
	initiate_structs(ants, lem_in);
	ants->amount = get_ants();
	input_scan(lem_in);
	add_room_to_array(lem_in);
	add_links_to_arrays(lem_in);
	testing_env(ants, lem_in);
	return (0);
}
