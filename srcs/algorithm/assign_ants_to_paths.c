/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ants_to_paths.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:07:48 by hopham            #+#    #+#             */
/*   Updated: 2020/03/28 15:14:20 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_ants_nb_in_path(t_list *paths, int ants)
{
	t_list	*i;
	t_list	*p;

	while (ants > 0)
	{
		i = paths;
		while (i && ants > 0)
		{
			p = (t_list*)i->content;
			ants--;
			p->content_size++;
			if (i->next && i->next->content_size >= i->content_size +
				p->content_size)
				break ;
			i = i->next;
		}
	}
	i = paths;
	while (i)
	{
		i->content_size = ((t_list*)i->content)->content_size;
		i = i->next;
	}
}
