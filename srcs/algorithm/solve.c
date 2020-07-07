/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:31:10 by HoangPham         #+#    #+#             */
/*   Updated: 2020/07/07 15:16:58 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    solve(t_lem *lem_in)
{
    t_queue *q;
    t_path  *path_list;

    if (!(q = (t_queue*)ft_memalloc(sizeof(t_queue))))
        ft_error("failed allocate queue memory");
    initiate_queue(lem_in, q);
	edmonds_karp(lem_in, q, &path_list);
	lem_in->steps = 0;
	ft_printf("\n");
	print_ants(lem_in, path_list);
}
