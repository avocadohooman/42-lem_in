/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:04 by hopham            #+#    #+#             */
/*   Updated: 2020/03/02 11:14:54 by gmolin           ###   ########.fr       */
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

static void testing_env(t_ants *ants, t_path *path, t_lem *lem_in, int level)
{
	int i;

	i = 0;
	ft_printf("\nAmount of ants: %d\nStarting room: %s\nEnding room: %s\n", ants->amount, lem_in->start, lem_in->end);
	while (lem_in->link_list && i < lem_in->room_amount)
	{
		ft_printf("room name: %10s -> room index: %d\n", lem_in->rooms[i]->name, lem_in->rooms[i]->pos);
		lem_in->link_list = lem_in->link_list->next;
		i++;
	}

	ants->amount = ants->amount;

	int  k = 0;
	i = 0;
	while (i < lem_in->room_amount)
	{
		k = 0;
		ft_printf("room %d: ", i);
		while (k < lem_in->room_amount)
		{
			ft_printf("%d ",lem_in->links[i][k]);
			k++;
		}
		ft_printf("\n");
		i++;
	}
	i = 0;
	k = 0;
	while (k < level)
	{
		i = 0;
		while (lem_in->paths[k][i])
		{
			ft_printf("%d -> ", lem_in->paths[k][i]);
			i++;
		}
		ft_printf("%d\n", lem_in->paths[k][i]);
		k++;
	}
	ft_printf("Shortest paths:\n");
	i = 0;
	while (i < path->nb_shortest_paths)
	{
		k = 0;
		while (path->shortest[i][k])
		{
			ft_printf("%i -> ", path->shortest[i][k]);
			k++;
		}
		ft_printf("%d\n", path->shortest[i][k]);
		i++;
	}
	ft_printf("Filtered paths:\n");
	i = 0;
	while (i < 1)
	{
		k = 0;
		while (lem_in->filtered[i][k])
		{
			ft_printf("%i -> ", lem_in->filtered[i][k]);
			k++;
		}
		ft_printf("%d\n", lem_in->filtered[i][k]);
		i++;
	}
}

int			main(void)
{
	t_ants 	*ants;
	t_lem 	*lem_in;
	t_path	*shortest_path;
	int i;

	i = 0;
	if (!(ants = (t_ants*)ft_memalloc(sizeof(t_ants))))
		return (0);
	if (!(lem_in = (t_lem*)ft_memalloc(sizeof(t_lem))))
		return (0);
	initiate_structs(ants, lem_in);
	ants->amount = get_ants();
	input_scan(lem_in);
	add_room_to_array(lem_in);
	add_links_to_arrays(lem_in);
	if (!path_search(lem_in))
		ft_error("ERROR: no path");
	while (path_search(lem_in) == 1) 
	{
		create_paths(lem_in, i);
		i++;
	}
	shortest_path = path(lem_in->paths, i, lem_in);
	sort_paths(shortest_path, lem_in, i);
	testing_env(ants, shortest_path, lem_in, i);
	return (0);
}
