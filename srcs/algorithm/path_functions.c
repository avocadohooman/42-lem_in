/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:40:50 by HoangPham         #+#    #+#             */
/*   Updated: 2020/07/10 13:13:35 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*ft_new_path(int *path, int len)
{
	t_path	*new;

	if (!(new = ft_memalloc(sizeof(t_path) + (sizeof(int) * (len + 1)))))
		ft_error("error memalloc new_path");
	if (path == NULL)
	{
		new->path = NULL;
		new->len = 0;
	}
	else
	{
		if (!(new->path = ft_memalloc(sizeof(int) * (len + 1))))
			ft_error("error memalloc new->path");
		ft_memcpy(new->path, path, (len * (sizeof(int))));
		new->len = len;
	}
	new->next = NULL;
	return (new);
}

void	ft_add_path(t_path **path, t_path *new)
{
	t_path *tmp;

	if (!new)
		return ;
	else if ((*path)->path == NULL)
	{
		free_path(*path);
		(*path) = new;
		return ;
	}
	tmp = *path;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_path	*clean_path(t_path *path_list)
{
	t_path	*tmp;

	if (path_list->path == NULL && path_list->next->path != NULL)
	{
		path_list->next->max = path_list->max;
		tmp = path_list;
		path_list = path_list->next;
		ft_memdel((void*)&tmp);
	}
	return (path_list);
}

t_path	**set_path(t_path **path_list, int i, t_lem *lem_in)
{
	*path_list = clean_path(*path_list);
	(*path_list)->max = i;
	if (!((*path_list)->division = ant_distribution(lem_in, *path_list)))
		(*path_list)->len = -1;
	return (path_list);
}

void	free_path(t_path *path_list)
{
	t_path *tmp;

	tmp = path_list;
	while (tmp != NULL)
	{
		path_list = path_list->next;
		if (tmp->division != NULL)
			ft_memdel((void*)&tmp->division);
		ft_memdel((void*)&tmp->path);
		ft_memdel((void*)&tmp);
		tmp = path_list;
	}
}
