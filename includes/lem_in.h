/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:29 by hopham            #+#    #+#             */
/*   Updated: 2020/03/16 19:40:09 by HoangPham        ###   ########.fr       */
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

typedef struct	s_node
{
	int				content;
	struct s_node	*next;
}				t_node;

typedef struct	s_path
{
	t_node			*nodes;
	t_list			*first;
	struct	s_path	*next;
}				t_path;

typedef struct	s_queue
{
	int		pop;
	t_path	*path_list;
	t_node	*first_node;
	t_list	*first;
}				t_queue;	

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
	int		paths[100][100];
	int		steps;
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

// int				path_search(t_lem *lem_in);
t_path			*another_path_search(t_lem *lem_in);

/*
** ------ bfs_queue.c ------
*/

t_queue			*create_queue(void);
t_list			*pop_first_value(t_queue *queue);
int				pop_to_visit(t_queue *to_visit);
void			ft_enqueue(t_queue *queue, t_list *new);
t_list			*new_list(int i);
t_list			*get_connecting_rooms(int visiting, int *visited, t_lem *lem);
void			visit(int visiting, t_lem *lem);

/*
** ------ create_paths.c ------
*/

void			create_paths(t_lem *lem, int level);
t_list			*path_search(t_lem *lem_in, int *visited, int end);
int				dereference(int *p);
t_list			*get_path_list(t_lem *lem);

/*
** ------ assign_ants_to_paths.c ------
*/

void			find_ants_nb_in_path(t_list *paths, int ants);


/*
** ------ assign_ants_to_paths.c ------
*/

void			print_ants(int nb_ants, t_lem *lem_in, t_ants *ants);
/*
** ------ error.c ------
*/

void			ft_error(char *str);

#endif
