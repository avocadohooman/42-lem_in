/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:15:23 by hopham            #+#    #+#             */
/*   Updated: 2020/03/02 13:03:41 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		remove_path(t_lem *lem_in)
{
	int i;

	i = 0;
	while (lem_in->paths[lem_in->short_pos][i])
	{
		lem_in->paths[lem_in->short_pos][i] = 0;
		i++;
	}
}

static void		copy_path(t_lem *lem_in, t_path *shortest_path, int k)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (shortest_path->shortest[0][i])
		lem_in->filtered[k][j++] = shortest_path->shortest[0][i++];
}

void			sort_paths(t_path **shortest_path, t_lem *lem_in, int level)
{
	int k;
	int i;

	k = 0;
	i = 0;
	level = level + 1;
	filtered_malloc(lem_in);
	copy_path(lem_in, *shortest_path, k);
	k++;
	remove_path(lem_in);
	*shortest_path = path(lem_in->paths, level, lem_in);
	copy_path(lem_in, *shortest_path, k);
	k++;
	remove_path(lem_in);
	*shortest_path = path(lem_in->paths, level, lem_in);
}
