/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:14:39 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/05 19:23:57 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		set_weights(t_lem *lem_in)
{
	int i;

	i = -1;
	while (++i < lem_in->room_amount)
		lem_in->rooms[i]->weight = __INT_MAX__;
	lem_in->rooms[0]->weight = 0;
}