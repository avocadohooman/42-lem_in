/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:52:10 by hopham            #+#    #+#             */
/*   Updated: 2020/07/08 17:00:33 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_malloc(t_lem *lem_in)
{
	int	i;

	lem_in->room_amount = ft_lstcount(lem_in->name_list);
	if (!(lem_in->rooms = (t_room**)ft_memalloc(sizeof(**lem_in->rooms)
									* lem_in->room_amount)))
		ft_error("ERROR: malloc problem");
	i = 0;
	while (i < lem_in->room_amount)
	{
		if (!(lem_in->rooms[i] = (t_room*)ft_memalloc(sizeof(t_room))))
			ft_error("ERROR: malloc problem");
		lem_in->rooms[i]->links_nb = 0;
		if (!(lem_in->rooms[i]->links = (int*)ft_memalloc(sizeof(int)
		* lem_in->room_amount)))
			ft_error("ERROR: malloc problem");
		i++;
	}
}

void	links_malloc(t_lem *lem_in)
{
	int i;

	if (!(lem_in->links = (int**)ft_memalloc(sizeof(int*)
		* lem_in->room_amount)))
		ft_error("ERROR: malloc problem links int");
	i = 0;
	while (i < lem_in->room_amount)
	{
		if (!(lem_in->links[i] = (int*)ft_memalloc(sizeof(int)
								* lem_in->room_amount)))
			ft_error("ERROR: malloc problem links int");
		i++;
	}
}

void	ft_strsplit_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free((void*)str);
}
