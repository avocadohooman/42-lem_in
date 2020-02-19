/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:29 by hopham            #+#    #+#             */
/*   Updated: 2020/02/19 16:52:17 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H


/*
** ------ HEADERS ------
*/

#include "ft_printf.h"
#include "get_next_line.h"
#include <stdio.h>


/*
** ------ STRUCTS ------
*/

typedef struct	s_link
{
	char			*from;
	char			*to;
	int				visited;
	struct s_link	*next;
}				t_link;

typedef struct 	s_room
{
	int		**links;
	char	*start;
	char	*end;
	char	*name;
	int		c_start;
	int		c_end;
	t_list	*name_list;
	t_link	*link_list;
	t_list	*connections;
}				t_room;

typedef struct 	s_ants
{
	int		amount;
	t_list	*links;
}				t_ants;

/*
** ------ lem_in.c ------
*/

int				main(void);

/*
** ------ read_input.c ------
*/

int				input_scan(t_room *room);

/*
** ------ initiate_structs.c ------
*/

void			initiate_structs(t_ants *ants, t_room *room);

/*
** ------ add_rooms.c ------
*/

void			add_rooms(char *type, char **line, t_room *room);

/*
** ------ add_links.c ------
*/

void			add_links(t_room *rooms, char *line);

/*
** ------ path_search.c ------
*/

void			path_search(t_room *room);

/*
** ------ error.c ------
*/

void			ft_error(char *str);

#endif
