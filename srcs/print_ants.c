/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmolin <gmolin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:40:13 by gmolin            #+#    #+#             */
/*   Updated: 2020/03/17 15:27:03 by gmolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void     print_ant(t_ants *ant, t_lem *lem_in)
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

static void     move_ants(t_list **ant_list, t_lem *lem_in, int *can_continue)
{
    t_list  *i;
    t_ants  *current;

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

static int     add_ants(t_list *path_stack, t_list **ant_list, int nb_ants, int *ants_left)
{
    t_list	*i;
	t_ants	*ta;
	t_list	*tal;
	int		tr;

	if (*ants_left < 1)
		return (0);
	i = path_stack;
	tr = 0;
	while (i && i->content_size > 0 && *ants_left > 0)
	{
		ta = (t_ants *)malloc(sizeof(t_ants));
		ta->links = (t_list *)i->content;
		ta->amount = (nb_ants - *ants_left) + 1;
		tal = (t_list *)malloc(sizeof(t_list));
		tal->content = ta;
		tal->content_size = sizeof(ta);
		ft_lstadd(ant_list, tal);
		(*ants_left)--;
		tr = 1;
		i->content_size--;
		i = i->next;
	}
	return (tr);
}

void            print_ants(int nb_ants, t_lem *lem_in, t_ants *ants)
{
	t_list	*ant_list;
    t_list  *path_stack;
	int		move_forward;
	int		ants_left;

	if (!ants)
		return ;
	path_stack = get_path_list(lem_in);
	find_ants_nb_in_path(path_stack, ants->amount);
	ant_list = NULL;
	move_forward = 1;
	ants_left = nb_ants;
	while (move_forward)
	{
		move_ants(&ant_list, lem_in, &move_forward);
        if (ant_list && move_forward)
		{
			lem_in->steps += 1;
			ft_putchar('\n');
		}
		move_forward = add_ants(path_stack, &ant_list, nb_ants, &ants_left) || move_forward;
	}
	ft_printf("\nTotal Amount of Steps: %d\n", lem_in->steps);
	ft_lstdel(&path_stack, &delete_paths);
	ft_lstdel(&ant_list, &delete_generic);
}
