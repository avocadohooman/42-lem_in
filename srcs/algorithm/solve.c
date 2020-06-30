/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:31:10 by HoangPham         #+#    #+#             */
/*   Updated: 2020/06/30 15:37:04 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    solve(t_lem *lem_in)
{
    t_queue q;
    t_path  *path_list;

    initiate_queue(lem_in, &q);
	edmonds_karp(lem_in, &q, &path_list);
}
