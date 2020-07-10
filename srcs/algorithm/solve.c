/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:31:10 by HoangPham         #+#    #+#             */
/*   Updated: 2020/07/10 13:03:34 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	solve(t_lem *lem_in)
{
	t_queue	*q;
	t_path	*path_list;

	if (!(q = (t_queue*)ft_memalloc(sizeof(t_queue))))
		ft_error("failed allocate queue memory");
	initiate_queue(lem_in, q);
	if (edmonds_karp(lem_in, q, &path_list) == 0)
		ft_error("ERROR: no path found");
	lem_in->steps = 0;
	ft_printf("\n");
	print_ants(lem_in, path_list);
	free_path(path_list);
	free_queue(q);
}
