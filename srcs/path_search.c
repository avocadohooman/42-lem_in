/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:14 by gmolin            #+#    #+#             */
/*   Updated: 2020/03/02 10:19:03 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_queue(t_queue *queue)
{
	t_node	*tmp;

	tmp = queue->first;
	while (tmp)
	{
		ft_printf("%i ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int		path_search(t_lem *lem_in)
{
	t_queue	*queue;
	int		**arr;
	int		r1;
	int		r2;
	int		*visited;

	if (!(visited = (int*)ft_memalloc(sizeof(int) * lem_in->room_amount)))
		ft_error("ERROR: allocate memory array visited");
	arr = lem_in->links;
	queue = create_queue();
	ft_enqueue(queue, 0);
	while (queue->first != NULL)
	{
		pop_first_value(queue);
		r1 = queue->pop;
		r2 = 0;
		while (r2 < lem_in->room_amount)
		{
			if (visited[r2] == 0 && arr[r1][r2] == 1)
			{
				ft_enqueue(queue, r2);
				visited[r2] = 1;
			}
			r2++;
		}
	}
	r1 = visited[lem_in->room_amount - 1];
	free(visited);
	free(queue);
	return (r1);
}
