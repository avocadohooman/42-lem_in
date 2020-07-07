/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:43:29 by hopham            #+#    #+#             */
/*   Updated: 2020/07/07 15:12:28 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
** ------ HEADERS ------
*/

# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>

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

typedef struct s_path
{
	int				*path;
	int				len;
	int				max;
	int				steps;
	int				*division;
	int				longest;
	struct s_path	*next;
}				t_path;

typedef struct	s_queue
{
	int		pop;
	int		len;
	int		*queue;
	int		*visited;
	int		*pre_room;
	int		**flow;
	int		position;
	t_list	*first;
}				t_queue;

typedef struct	s_room
{
	char			*name;
	int				links_nb;
	int				*links;
	int				pos;
	int				empty;
}				t_room;

typedef struct	s_lem
{
	int			**links;
	char		*start;
	char		*end;
	char		*name;
	int			room_amount;
	int			*room_p;
	int			room;
	int			start_pos;
	int			end_pos;
	int			c_end;
	int			c_start;
	int			steps;
	int			max_flow;
	long long	ant_amount;
	long long	move_ants;
	t_room	**rooms;
	t_list	*name_list;
	t_link	*link_list;
}				t_lem;

typedef	struct	s_ants
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
** ------ queue_functions.c ------
*/

void			initiate_queue(t_lem *lem_in, t_queue *q);
void			clear_queue(t_queue *q);
void			reset_queue(t_queue *q, int start, int end);
void			set_to_n(int *set, int length, int n);


/*
** ------ optimise.c ------
*/

int				*divide_ants(t_lem *lem_in, t_path *path_list);


/*
** ------ path_functions.c ------
*/

t_path			*ft_new_path(int *path, int len);
void			ft_add_path(t_path **path, t_path *new);
t_path			**set_path(t_path **path_list, int i, t_lem *lem_in);
t_path  		*clean_path(t_path *path_list);
void			free_path(t_path *path_list);

/*
** ------ bfs.c ------
*/

int				bfs(t_lem *lem_in, t_queue *q);

/*
** ------ save_path.c ------
*/

t_path			**save_path(t_lem *lem_in, t_queue *q, t_path **path_list);

/*
** ------ edmonds_karp.c ------
*/

int				edmonds_karp(t_lem *lem_in, t_queue *q, t_path **p);

/*
** ------ edmonds_karp.c ------
*/

void			solve(t_lem *lem_in);

/*
** ------ bfs_queue.c ------
*/

t_queue			*create_queue(void);
int				pop_to_visit(t_queue *to_visit);
void			ft_enqueue(t_queue *queue, t_list *new);
t_list			*new_list(int i);

/*
** ------ path_search.c ------
*/

int				dereference(int *p);
t_list			*get_path_list(t_lem *lem);

/*
** ------ path_search_help.c ------
*/

t_list			*path_search(t_lem *lem_in, int *visited, int end);

/*
** ------ path_search_help2.c ------
*/

void			*freeing(t_list	*i);

/*
** ------ assign_ants_to_paths.c ------
*/

void			find_ants_nb_in_path(t_list *paths, int ants);

/*
** ------ path_set_dispatcher.c ------
*/

void			calc_steps_path(t_lem *lem_in, t_path *new_path);

/*
** ------ print_ants.c ------
*/

// void			print_ants(int nb_ants, t_lem *lem_in, t_ants *ants, t_path *path_list);
int				print_ants(t_lem *lem_in, t_path *paths);


/*
** ------ ant_functions.c ------
*/

t_path		*reset_ants(int *x, int *i, t_path *paths);
int			check_print_space(int x);
int			*get_path_lengths(t_lem *lem_in, t_path *paths, int *total);
int			send_new_ant(t_lem *lem_in, int *p, int mov, int *fin);

/*
** ------ weight_functions.c ------
*/
void		set_weights(t_lem *lem_in);
int			check_weights(t_room *next, t_room *current, t_queue *q, t_lem *lem_in);


/*
** ------ error.c ------
*/

void			ft_error(char *str);
void			ft_strsplit_free(char **str);

/*
** ------ delete.c ------
*/

void			delete_generic(void *content, size_t content_size);
void			delete_paths(void *content, size_t content_size);

#endif
