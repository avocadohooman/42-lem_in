/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:06:26 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/05 19:30:22 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_print_space(int x)
{
	if (x != 0)
		ft_printf(" ");
	x = 1;
	return (x);
}

t_path	*reset_ants(int *x, int *i, t_path *paths)
{
	x[0] = 0;
	i[0] = -1;
	return (paths);
}

int		*get_path_lengths(t_lem *lem_in, t_path *paths, int *total)
{
	int		i;
	int		*steps;
	t_path	*path;

	i = 0;
	path = paths;
	if (!(steps = (int *)ft_memalloc(sizeof(int) * lem_in->max_flow)))
		return (NULL);
	while (i < lem_in->max_flow)
	{
		steps[i] = path->len;
		total[0] = total[0] + steps[i];
		++i;
		path = path->next;
	}
	return (steps);
}