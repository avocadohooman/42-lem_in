/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_set_dispatcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:52:56 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/07 15:21:27 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		calc_steps_path(t_lem *lem_in, t_path *new_path)
{
	t_path	*start;

	start = new_path;
	while (new_path)
	{
		lem_in->steps++;
		new_path = new_path->next;
	}
	lem_in->steps++;
	new_path = start;
}
