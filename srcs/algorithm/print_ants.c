/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:34:24 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/08 17:18:09 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** First we go to the end of the path and the iterate backwards until
** we find an ant.
*/

static	int		find_last_ant(t_lem *lem_in, int *path)
{
	int i;

	i = 0;
	while (path[i] != lem_in->end_pos)
		i++;
	while (i != 0 && lem_in->rooms[path[i]]->empty == -1)
		i--;
	return (i + 1);
}

/*
** If we reached the finish line of a path, we remove it from
** the path and return 1
*/

static int		reach_end(int *path, t_lem *lem_in, int i, int *x)
{
	if (path[i] == lem_in->end_pos)
	{
		x[0] = check_print_space(x[0]);
		ft_printf("L%d-%s", lem_in->rooms[path[i - 1]]->empty,
		lem_in->rooms[path[i]]->name);
		if (i >= 1)
			lem_in->rooms[path[i - 1]]->empty = -1;
		return (1);
	}
	return (0);
}

/*
** If index is empty (i) and the place before (i) is not empty,
** move the ant to (i)
*/

static void		move_ant(int *path, t_lem *lem_in, int i, int *x)
{
	if (lem_in->rooms[path[i]]->empty == -1 && i > 1 &&
	lem_in->rooms[path[i - 1]]->empty != -1)
	{
		lem_in->rooms[path[i]]->empty = lem_in->rooms[path[i - 1]]->empty;
		lem_in->rooms[path[i - 1]]->empty = -1;
		x[0] = check_print_space(x[0]);
		ft_printf("L%d-%s", lem_in->rooms[path[i]]->empty,
		lem_in->rooms[path[i]]->name);
	}
}

/*
** We find the last ant in each path by going backwards. Then
**we move the ant forward and check if we reached the end.
*/

static	void	move_ants_on_path(t_lem *lem_in, int *path, int *x)
{
	int	i;

	i = find_last_ant(lem_in, path);
	if (path[0] == lem_in->start_pos && path[1] == lem_in->end_pos)
		return ;
	while (i != 0)
	{
		if ((reach_end(path, lem_in, i, x)) == 1)
			lem_in->arr_a++;
		else if (lem_in->arr_a < lem_in->ant_amount)
			move_ant(path, lem_in, i, x);
		i--;
	}
}

/*
** We go through each path, moving the ants on the path until the end is
** reached, then sending new ants until capacity has reached.
*/

int				print_ants(t_lem *lem_in, t_path *paths)
{
	int		arrived_ants;
	int		i;
	int		x;
	t_path	*curr_p;

	arrived_ants = 0;
	x = 0;
	i = -1;
	while (lem_in->arr_a < lem_in->ant_amount && ++lem_in->steps)
	{
		curr_p = reset_ants(&x, &i, paths);
		while (++i < paths->max)
		{
			move_ants_on_path(lem_in, curr_p->path, &x);
			if (lem_in->mv_a < lem_in->ant_amount && paths->division[i] > 0)
			{
				x = check_print_space(x);
				lem_in->mv_a = send_new_ant(lem_in, curr_p->path);
				paths->division[i]--;
			}
			curr_p = curr_p->next;
		}
		ft_printf("\n");
	}
	return (lem_in->steps);
}
