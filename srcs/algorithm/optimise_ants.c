/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:26:11 by gmolin            #+#    #+#             */
/*   Updated: 2020/07/05 20:01:15 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	*calculate_divide(int *ant_div, t_lem *lem_in, int total, int *steps)
{
	int		i;

	i = 0;
	total = (total + lem_in->ant_amount ) / lem_in->max_flow;
	while (i < lem_in->max_flow)
	{
		ant_div[i] = total - steps[i];
		++i;
	}
	return (ant_div);
}

static int	*split_remainder(int *division, int remainder, t_path **paths)
{
	int		i;
	int		full;

	full = 0;
	while (remainder > 0)
	{
		i = 0;
		while (i < (*paths)->max)
		{
			if (division[i] + 1 <= (*paths)->longest)
			{
				--remainder;
				++division[i];
			}
			if (division[i] >= (*paths)->longest)
				++full;
			if (full == (*paths)->max)
			{
				full = 0;
				++(*paths)->longest;
			}
			++i;
		}
	}
	return (division);
}

static int	*check_total_ants(int *division, t_lem *lem_in, t_path **paths)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < (*paths)->max)
	{
		total = total + division[i];
		++i;
	}
	if (total < lem_in->ant_amount)
		division = split_remainder(division, lem_in->ant_amount - total, paths);
	return (division);
}

static int	get_longest(int *division, int *steps, int max)
{
	int		i;
	int		longest;

	i = -1;
	longest = 0;
	while (++i < max)
	{
		if (longest < steps[i] + division[i] - 1)
			longest = steps[i] + division[i] - 1;
	}
	return (longest);
}

int			*divide_ants(t_lem *lem_in, t_path *path_list)
{
	int		*division;
	int		*steps;
	int		total;

	total = 0;
	division = (int *)ft_memalloc(sizeof(int) * path_list->max);
	lem_in->max_flow = path_list->max;
	if (path_list->max == 1)
	{
		division[0] = lem_in->ant_amount;
		return (division);
	}
	if ((steps = get_path_lengths(lem_in, path_list, &total)) == NULL)
		return (NULL);
	division = calculate_divide(division, lem_in, total, steps);
	path_list->longest = get_longest(division, steps, path_list->max);
	division = check_total_ants(division, lem_in, &path_list);
	path_list->longest = get_longest(division, steps, path_list->max);
	ft_memdel((void*)&steps);
	return (division);
}