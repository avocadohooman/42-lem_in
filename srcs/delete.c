/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:20:52 by gmolin            #+#    #+#             */
/*   Updated: 2020/03/17 15:21:46 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void		delete_generic(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

void		delete_paths(void *content, size_t content_size)
{
	t_list	*ts;

	ts = (t_list *)content;
	content_size = 0;
	ft_lstdel(&ts, &delete_generic);
}