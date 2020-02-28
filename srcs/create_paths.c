/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:48:54 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/28 14:15:41 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_visited(t_lem *lem, int level, int nb)
{
	int i;
	// int k;

	i = 0;
	// k = level;
	// while (k < level)
	// {
	// 	i = 0;
		while (lem->paths[level][i])
		{
			if (lem->paths[level][i] == nb)
				return (0);
			i++;
		}
		// level++;
	// }
	return (1);
}

static void		switch_negative(t_lem *lem, int pos, int i)
{
	if (i != 0 && pos != 0 && pos != lem->room_amount - 1)
	{
		lem->links[pos][i] = -1;	
		lem->links[i][pos] = -1;
	}
	else if (lem->links[pos][0] == 1 && lem->links[pos][lem->room_amount - 1] == 1)
	{
		lem->links[pos][lem->room_amount - 1] = -1;	
		lem->links[lem->room_amount - 1][pos] = -1;
	}
}

static void		check_dead_end(t_lem *lem, int level, int pos, int i)
{
	i = 0;
	if (pos != 0)
	{
		while (lem->paths[level][i])
		{
			lem->paths[level][i] = 0;
			i++;
		}
		pos = lem->room_amount - 1;
		while (i < lem->room_amount - 1)
		{
			if (lem->links[pos][i] == 1)
			{
				lem->links[pos][i] = -1;
				lem->links[i][pos] = -1;
				break ;
			}
			i++;
		}
	}
}

void			create_paths(t_lem *lem, int level)
{
	int	pos;
	int i;
	int c;

	lem->paths[level][0] = lem->room_amount - 1;
	c = 1;
	i = 0;
	pos = lem->room_amount - 1;
	while (i < lem->room_amount - 1)
	{
		if (lem->links[pos][i] == 1)
		{
			switch_negative(lem, pos, i);
			if (check_visited(lem, level, i) == 1)
				lem->paths[level][c] = i;
			pos = i;
			i = 0;
			c++;
			if (pos == 0)
			{
				lem->paths[level][c] = 0;
				break ;
			}
			else 
				continue ;
		}
		i++;
	}
	check_dead_end(lem, level, pos, i);
}
