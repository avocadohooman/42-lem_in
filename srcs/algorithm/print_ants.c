/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:21:55 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/03 15:59:37 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ants(t_lem *lem_in, t_ants *ants, t_path *p, int x)
{
	int		finished_ants;
	int		move_ants;
	int		i;
	t_path	*path;

	move_ants = 0;
	finished_ants = 0;
	while (finished_ants < ants->amount)
	{
		path = reset_ants(&x, &i, p);
		while (++i < lem_in->max_flow)
		{
			move_ants_on_path(lem_in, p->path, &finished_ants, &x);
			if (move_ants <)
		}
	}
}