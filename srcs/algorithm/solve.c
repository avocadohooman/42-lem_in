/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:31:10 by HoangPham         #+#    #+#             */
/*   Updated: 2020/06/30 17:44:49 by HoangPham        ###   ########.fr       */
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
}
