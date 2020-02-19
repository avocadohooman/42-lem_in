/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:36:37 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/19 16:29:09 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		initiate_ants(t_ants *ants)
{
	ants->amount = 0;
}

static void		initiate_rooms(t_room *room)
{
	room->start = NULL;
	room->end = NULL;
	room->c_start = 0;
	room->c_end = 0;
}

void			initiate_structs(t_ants *ants, t_room *room)
{
	initiate_ants(ants);
	initiate_rooms(room);
}
