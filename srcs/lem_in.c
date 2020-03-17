/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:04 by hopham            #+#    #+#             */
/*   Updated: 2020/03/17 13:11:49 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_ants(void)
{
	char		*line;
	int			ant_numbers;
	size_t		i;

	i = 0;
	while (1)
	{
		get_next_line(0, &line);
		if (!ft_strstr(line, "#"))
			break ;
		ft_strdel(&line);
	}
	while (i < ft_strlen(line))
	{
		if (!ft_isdigit(line[i]))
			ft_error("ERROR: invalid input");
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
	ft_printf("\n");
	print_ants(ants->amount, lem_in, ants);
	return (0);
}
