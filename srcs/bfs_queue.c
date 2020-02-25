/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:10:39 by hopham            #+#    #+#             */
/*   Updated: 2020/02/25 11:16:52 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*create_queue(void)
{
	t_queue	*queue;

	if (!(queue= (t_queue*)ft_memalloc(sizeof(t_queue))))
		ft_error("ERROR: allocate memory queue");
	queue->first = NULL;
	return (queue);
}
