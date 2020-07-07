/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:04 by hopham            #+#    #+#             */
/*   Updated: 2020/07/07 15:08:49 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ants(void)
{
	char		*line;
	int			ant_numbers;
	size_t		i;

	i = 0;
	while (get_next_line(0, &line))
	{
		if (!ft_strstr(line, "#") && ft_strlen(line) > 0)
			break ;
		else if (!ft_strlen(line))
			continue ;
		(ft_strlen(line) > 0) ? ft_printf("%s\n", line) : 0;
		ft_strdel(&line);
	}
	while (i < ft_strlen(line))
	{
		(!ft_isdigit(line[i])) ? ft_error("ERROR: invalid input") : 0;
		i++;
	}
	ant_numbers = ft_atoi(line);
	ft_strdel(&line);
	ft_printf("%d\n", ant_numbers);
	if (ant_numbers <= 0 || ant_numbers > INT_MAX)
		ft_error("ERROR: ant_numbers is not valid");
	return (ant_numbers);
}

int			main(void)
{
	t_ants	*ants;
	t_lem	*lem_in;

	if (!(ants = (t_ants*)ft_memalloc(sizeof(t_ants))))
		return (0);
	if (!(lem_in = (t_lem*)ft_memalloc(sizeof(t_lem))))
		return (0);
	initiate_structs(ants, lem_in);
	ants->amount = get_ants();
	lem_in->ant_amount = ants->amount;
	input_scan(lem_in);
	add_room_to_array(lem_in);
	add_links_to_arrays(lem_in);
	solve(lem_in);
	ft_printf("\nTotal Steps: %d\n", lem_in->steps);
	free(ants);
	return (0);
}
