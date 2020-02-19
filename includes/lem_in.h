/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:29 by hopham            #+#    #+#             */
/*   Updated: 2020/02/19 12:12:24 by hopham           ###   ########.fr       */
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

typedef struct 	s_room
{
	int		**links;
	char	*start;
	char	*end;
	char	*name;
	int		c_start;
	int		c_end;
	t_list	*name_list;
	t_list	*links_list;
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
** ------ error.c ------
*/

void			ft_error(char *str);

#endif
