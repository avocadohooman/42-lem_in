/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:15:23 by hopham            #+#    #+#             */
/*   Updated: 2020/03/02 18:13:28 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		remove_shortest_path(t_lem *lem_in, t_path *shortest_path)
{
	int i;
	int	k;

	i = 0;
	k = 0;
	while (k < shortest_path->nb_shortest_paths)
	{
		i = 0;
		while (lem_in->paths[lem_in->short_pos[k]][i])
		{
			lem_in->paths[lem_in->short_pos[k]][i] = 0;
			i++;
		}
		k++;
	}
}

static void		copy_path(t_lem *lem_in, t_path *shortest_path)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	while (k < shortest_path->nb_shortest_paths)
	{
		i = 0;
		j = 0;
		while (shortest_path->shortest[k][i])
			lem_in->filtered_short[k][j++] = shortest_path->shortest[k][i++];
		k++;
	}
}

static	int		filter(t_lem *lem_in, t_path *shortest_path)
{
	int i;
	int k;
	int token;

	k = 0;
	token = 0;
	while (k < shortest_path->nb_shortest_paths)
	{
		i = 1;
		while (lem_in->filtered_short[k][i] && lem_in->filtered_short[k][i] != 0)
		{
			if (lem_in->filtered_short[k][i] == shortest_path->shortest[k][i])
			{
				lem_in->bad_path = k;
				token++;
				if (token == shortest_path->nb_shortest_paths - 1)
					return (0);
			}
			i++;
		}
		k++;
	}
	return (1);
}

void			sort_paths(t_path **shortest_path, t_lem *lem_in, int level)
{
	int k;
	int i;

	k = 0;
	i = 0;
	filtered_malloc(lem_in);
	copy_path(lem_in, *shortest_path);
	remove_shortest_path(lem_in, *shortest_path);
	while (k < lem_in->nb_paths)
	{
		*shortest_path = path(lem_in->paths, level, lem_in);
		if (!filter(lem_in, *shortest_path))
		{
			while (lem_in->filtered_short[lem_in->bad_path][i] && (*shortest_path)->nb_shortest_paths > 1)
			{
				lem_in->filtered_short[lem_in->bad_path][i] = 0;
				i++;
			}		
		}
		k++;
	}
}
