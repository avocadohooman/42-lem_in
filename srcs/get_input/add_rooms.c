/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:10:08 by hopham            #+#    #+#             */
/*   Updated: 2020/07/10 11:01:14 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_coordinates(char **room)
{
	int i;
	int k;

	k = 1;
	while (room[k])
	{
		i = 0;
		while (room[k][i])
		{
			if (!ft_isdigit(room[k][i]))
				ft_error("ERROR: invalid input");
			i++;
		}
		k++;
	}
}

static void		validate(t_lem *lem_in)
{
	int		i;
	t_list	*tmp;

	tmp = lem_in->name_list;
	i = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->content, lem_in->name))
			i++;
		if (i > 1 || lem_in->name[0] == 'L' || lem_in->name[0] == '#')
			ft_error("ERROR: Duplicates");
		tmp = tmp->next;
	}
}

void			add_rooms(char *type, char **line, t_lem *lem_in)
{
	char	**strsplit;

	strsplit = ft_strsplit(*line, ' ');
	if (strsplit[0] == NULL)
		return ;
	check_coordinates(strsplit);
	if (!ft_strcmp(type, "start"))
		lem_in->start = ft_strdup(strsplit[0]);
	else if (!ft_strcmp(type, "end"))
		lem_in->end = ft_strdup(strsplit[0]);
	lem_in->name = strsplit[0];
	if (lem_in->name_list)
		ft_lstadd_end(&lem_in->name_list, ft_lstnew_str(lem_in->name));
	else
		lem_in->name_list = ft_lstnew_str(lem_in->name);
	validate(lem_in);
	ft_printf("%s\n", *line);
	ft_strdel(line);
	ft_strsplit_free(strsplit);
}
