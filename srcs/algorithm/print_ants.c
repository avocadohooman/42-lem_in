/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:34:24 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/06 22:08:53 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


/*
** First we go to the end of the path and the iterate backwards until we find an ant. 
*/

static 	int 	find_last_ant(t_lem *lem_in, int *path)
{
	int j;

	j = 0;
	// ft_printf("end pos: %d\n", lem_in->end_pos);
	while (path[j] != lem_in->end_pos)
	{
		j++;
		// ft_printf("patj[j]: %d\n", path[j]);
	}
	while (j != 0 && lem_in->rooms[path[j]]->empty == -1)
		j--;
	return (j + 1);
}

/*
** If we reached the finish line of a path, we remove it from the path and return 1
*/

static int		reach_finish(int *path, t_lem *lem_in, int i, int *x)
{
	if (path[i] == lem_in->end_pos)
	{
		x[0] = check_print_space(x[0]);
		ft_printf("L%d-%s", lem_in->rooms[path[i - 1]]->empty, lem_in->rooms[path[i]]->name);
		if (i >= 1)
			lem_in->rooms[path[i -1]]->empty = -1;
		return (1);
	}
	return (0);
}

/*
** If index is empty (i) and the place before (i) is not empty, move the ant to (i)
*/

static void		move_ant(int *path, t_lem *lem_in, int i, int *x)
{
	if (lem_in->rooms[path[i]]->empty == -1 && i > 1 && lem_in->rooms[path[i - 1]]->empty != -1)
	{
		x[0] = check_print_space(x[0]);
		lem_in->rooms[path[i]]->empty = lem_in->rooms[path[i - 1]]->empty;
		lem_in->rooms[path[i - 1]]->empty = -1;
		ft_printf("L%d-%s", lem_in->rooms[path[i]]->empty, lem_in->rooms[path[i]]->name);
	}
}

/*
** We find the last ant in each path by going backwards. Then  we move the ant forward and check
** if we reached the end.
*/

static	void	move_ants_on_path(t_lem *lem_in, int *path, int *arrived_ants, int *x)
{
	int 	i;

	i = find_last_ant(lem_in, path);
	if (path[0] == lem_in->start_pos && path[1] == lem_in->end_pos)
		return ;
	while (i != 0)
	{
		if ((reach_finish(path, lem_in, i, x)) == 1)
			arrived_ants[0]++;
		else if (arrived_ants[0] < lem_in->ant_amount)
			move_ant(path, lem_in, i, x);
		i--;
	}
}

/*
** We go through each path, moving the ants on the path until the end is reached, then sending 
** new ants until capacity has reached. 
*/

int		print_ants(t_lem *lem_in, t_path *paths)
{
	int		arrived_ants;
	int		i;
	int		j;
	int		x;
	int		move_ants;
	t_path	*path;

	move_ants = 0;
	j = 0;
	arrived_ants = 0;
	x = 0;
	i = -1;
	while (arrived_ants < lem_in->ant_amount && (++j || 1))
	{
		path = reset_ants(&x, &i, paths);
		// ft_printf("\nARIVED ANTS: %i / %i, CURRENT STEP: %d\n", arrived_ants, lem_in->ant_amount , j);
 		while (++i < paths->max)
		{
			move_ants_on_path(lem_in, path->path, &arrived_ants, &x);
			if (move_ants < lem_in->ant_amount && paths->division[i] > 0)
			{
				x = check_print_space(x);
				move_ants = send_new_ant(lem_in, path->path, move_ants, &arrived_ants);
				paths->division[i]--;
			}
			path = path->next;
		}
		ft_printf("\n");
	}
	ft_printf("\nTOTAL STEPS: %d\n", j);
	return (j);
}
