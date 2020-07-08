/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:06:26 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/08 10:21:20 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Send a new ant on the path if the first room is empty, and we haven't
** sent any ant yet.
*/

int		send_new_ant(t_lem *lem_in, int *p, int mov, int *fin)
{
	int		i;

	i = 0;
	if (mov <= lem_in->ant_amount && lem_in->rooms[p[1]]->empty == -1)
	{
		++mov;
		lem_in->rooms[p[1]]->empty = mov;
		if (p[1] == lem_in->end_pos)
		{
			lem_in->rooms[p[1]]->empty = -1;
			++fin[0];
		}
		ft_printf("L%d-%s", mov, lem_in->rooms[p[1]]->name);
		i++;
	}
	return (mov);
}

/*
** Just checking if we need to print a space
*/

int		check_print_space(int x)
{
	if (x != 0)
		ft_printf(" ");
	x = 1;
	return (x);
}

/*
** Reset ant function after each step
*/


t_path	*reset_ants(int *x, int *i, t_path *paths)
{
	x[0] = 0;
	i[0] = -1;
	return (paths);
}

/*
** Here we calculate the total steps of each path and keep track
** of the total sum of all steps of all paths
*/

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
		i++;
		path = path->next;
	}
	return (steps);
}