/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:42:30 by hopham            #+#    #+#             */
/*   Updated: 2020/02/28 15:13:29 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Adds the element "new" at the beginnning of the list.
*/

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!(*alst))
	{
		*alst = ft_lstnew(new->content, new->content_size);
		return ;
	}
	new->next = *alst;
	*alst = new;
}
