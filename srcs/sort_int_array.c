/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:36:06 by hopham            #+#    #+#             */
/*   Updated: 2020/03/02 10:49:07 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_path_len(int *path_arr)
{
	int	i;

	i = 0;
	while (path_arr[i])
		i++;
	return (i);
}

int	shortest(int **arr_of_paths, int k)
{
	int	i;
	int	min;

	if (!(arr_of_paths))
		return (0);
	min = ft_path_len(arr_of_paths[0]);
	i = 0;
	while (i < k)
	{
		if (min > ft_path_len(arr_of_paths[i]) && ft_path_len(arr_of_paths[i]))
			min = ft_path_len(arr_of_paths[i]);
		i++;
	}
	return (min);
}

t_path	*path(int **arr_of_paths, int k, t_lem *lem_in)
{
	int		i;
	int		j;
	int		shortest_len;
	t_path	*path_lst;

	i = 0;
	j = 0;
	if (!(path_lst = (t_path*)ft_memalloc(sizeof(t_path))))
		ft_error("ERROR: allocate memory path");
	path_lst->shortest = (int**)ft_memalloc(sizeof(int*) * 1000);
	shortest_len = shortest(arr_of_paths, k);
	while (i < k)
	{
		if (ft_path_len(arr_of_paths[i]) == shortest_len)
		{
			path_lst->shortest[j] = (int*)ft_memalloc(sizeof(int) * 1000);
			path_lst->shortest[j] = arr_of_paths[i];
			j++;
			lem_in->short_pos = i;
		}
		i++;
	}
	path_lst->nb_shortest_paths = j;
	return (path_lst);
}
