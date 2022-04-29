/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:29:22 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/27 10:12:42 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
