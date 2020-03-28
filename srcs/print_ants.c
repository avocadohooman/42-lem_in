/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:40:13 by gmolin            #+#    #+#             */
/*   Updated: 2020/03/28 15:19:28 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ant(t_ants *ant, t_lem *lem_in)
{
	int		n;
	int		*room_pointer;
	char	*name;

	n = ant->amount;
	room_pointer = (int *)ant->links->content;
	name = lem_in->rooms[*room_pointer]->name;
	ft_putchar('L');
	ft_putnbr(n);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

static void	move_ants(t_list **ant_list, t_lem *lem_in, int *can_continue)
{
	t_list	*i;
	t_ants	*current;

	i = *ant_list;
	*can_continue = 0;
	while (i)
	{
		current = (t_ants *)i->content;
		if (current->links->next)
		{
			*can_continue = 1;
			current->links = current->links->next;
			print_ant(current, lem_in);
		}
		i = i->next;
	}
}

static int	add_ants(t_list *path_stack, t_list **a_lst, int nb_a, int *a_left)
{
	t_list	*i;
	t_ants	*ant;
	t_list	*ant_l;
	int		k;

	if (*a_left < 1)
		return (0);
	i = path_stack;
	k = 0;
	while (i && i->content_size > 0 && *a_left > 0)
	{
		ant = (t_ants *)malloc(sizeof(t_ants));
		ant->links = (t_list *)i->content;
		ant->amount = (nb_a - *a_left) + 1;
		ant_l = (t_list *)malloc(sizeof(t_list));
		ant_l->content = ant;
		ant_l->content_size = sizeof(ant);
		ft_lstadd(a_lst, ant_l);
		(*a_left)--;
		k = 1;
		i->content_size--;
		i = i->next;
	}
	return (k);
}

void		print_ants(int nb_ants, t_lem *lem_in, t_ants *ants)
{
	t_list	*ant_list;
	t_list	*path_stack;
	int		mv_fwd;
	int		a_left;

	if (!ants)
		return ;
	path_stack = get_path_list(lem_in);
	find_ants_nb_in_path(path_stack, ants->amount);
	ant_list = NULL;
	mv_fwd = 1;
	a_left = nb_ants;
	while (mv_fwd)
	{
		move_ants(&ant_list, lem_in, &mv_fwd);
		if (ant_list && mv_fwd)
		{
			lem_in->steps += 1;
			ft_putchar('\n');
		}
		mv_fwd = add_ants(path_stack, &ant_list, nb_ants, &a_left) || mv_fwd;
	}
	ft_printf("\nTotal Amount of Steps: %d\n", lem_in->steps);
	ft_lstdel(&path_stack, &delete_paths);
	ft_lstdel(&ant_list, &delete_generic);
}
