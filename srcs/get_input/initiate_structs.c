/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:36:37 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/08 17:08:49 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		initiate_ants(t_ants *ants)
{
	ants->amount = 0;
}

static void		initiate_rooms(t_lem *lem_in)
{
	lem_in->start = NULL;
	lem_in->end = NULL;
	lem_in->c_start = 0;
	lem_in->c_end = 0;
	lem_in->steps = 0;
	lem_in->mv_a = 0;
	lem_in->arr_a = 0;
}

void			initiate_structs(t_ants *ants, t_lem *room)
{
	initiate_ants(ants);
	initiate_rooms(room);
}
