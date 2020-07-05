/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:34:24 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/05 20:48:14 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static 	int 	find_last_ant(t_lem *lem_in, int *path)
{
	int j;

	j = 0;
	while (path[j] != lem_in->end_pos)
		j++;
	while (j != 0 &&  lem_in->rooms[path[j]] == -1)
		j--;
	return (j + 1);
}

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

int		print_ants2(t_lem *lem_in, t_path *paths)
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
			i++;
		}
		ft_printf("\n");
	}
	ft_printf("\nTOTAL STEPS: %d\n", j);
	return (j);
}
