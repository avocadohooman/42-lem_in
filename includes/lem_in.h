/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:29 by hopham            #+#    #+#             */
/*   Updated: 2020/02/24 18:19:44 by hopham           ###   ########.fr       */
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
	char			*name;
	unsigned int	visited;
	int				pos;
}				t_room;

typedef struct 	s_lem
{
	int		**links;
	char	*start;
	char	*end;
	char	*name;
	int		c_start;
	int		c_end;
	int		room_amount;
	t_room	**rooms;
	t_list	*name_list;
	t_link	*link_list;
	t_list	*connections;
}				t_lem;

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

int				input_scan(t_lem *room);

/*
** ------ initiate_structs.c ------
*/

void			initiate_structs(t_ants *ants, t_lem *lem_in);

/*
** ------ add_rooms.c ------
*/

void			add_rooms(char *type, char **line, t_lem *lem_in);

/*
** ------ add_links.c ------
*/

void			add_links(t_lem *lem_in, char *line);

/*
** ------ create_arrays.c ------
*/

void			room_malloc(t_lem *lem_in);
void			links_malloc(t_lem *lem_in);
void			add_room_to_array(t_lem *lem_in);
void			add_links_to_arrays(t_lem *lem_in);

/*
** ------ path_search.c ------
*/

void			path_search(t_lem *lem_in);

/*
** ------ error.c ------
*/

void			ft_error(char *str);

#endif
