/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:48:54 by gmolin            #+#    #+#             */
/*   Updated: 2020/03/16 17:43:32 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// static int		check_visited(t_lem *lem, int level)
// {
	
// }

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
			if (pos != lem->room_amount - 1)
				lem->links[pos][i] = -1;
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
			if (lem->links[pos][i] == 1 && i != 0 && pos != 0)
			{
				lem->links[pos][i] = -1;
				break ;
			}
			i++;
		}
	}
	i = 0;
	while (lem->paths[level][i])
	{
		ft_printf("%d ", lem->paths[level][i]);
		i++;
	}
	ft_printf("%d \n", lem->paths[level][i]);
}
