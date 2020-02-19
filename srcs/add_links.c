/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:11:05 by gmolin            #+#    #+#             */
/*   Updated: 2020/02/19 16:08:05 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	validate_link(t_room *rooms, char *name)
{
	t_list	*room_name;

	room_name = rooms->name_list;
	while (room_name)
	{
		if (!ft_strcmp(name, room_name->content))
			return ;
		room_name = room_name->next;
	}
	ft_error("ERROR: invalid links");
}

static t_link	*create_links_list(char *from, char *to)
{
	t_link	*links;

	if (!(links = (t_link*)ft_memalloc(sizeof(t_link))))
		ft_error("ERROR: cannot alocate memory");
	links->from = from;
	links->to = to;
	links->next = NULL;
	return (links);
}

static void		add_links_to_list(t_link **list, t_link *new_link)
{
	t_link	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_link;
	return ;
}

void		add_links(t_room *rooms, char *line)
{
	char	*from;
	char	*to;
	char	**split;

	ft_printf("%s\n", line);
	split = ft_strsplit(line, '-');
	from = split[0];
	to = split[1];
	validate_link(rooms, from);
	validate_link(rooms, to);
	if (!rooms->link_list)
		rooms->link_list = create_links_list(from, to);
	else
		add_links_to_list(&rooms->link_list, create_links_list(from, to));
}
