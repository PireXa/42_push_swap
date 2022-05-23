/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 15:11:23 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/05 13:44:56 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*rotater(t_stack *stck)
{
	t_stack	*tmp;

	if (!stck || ft_lstsize(stck) < 2)
		return (stck);
	tmp = stck->next;
	stck->next = NULL;
	ft_lstlast(tmp)->next = stck;
	stck = tmp;
	return (stck);
}

void	*super_rotater(t_supsta *sup)
{
	sup->a = rotater(sup->a);
	sup->b = rotater(sup->b);
	return (sup);
}

static t_stack	*ft_stck_last_menos_um(t_stack *stck)
{
	t_stack	*temp;

	if (!stck)
		return (NULL);
	temp = stck;
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

t_stack	*reverse_rotater(t_stack *stck)
{
	t_stack	*tmp;

	if (!stck || ft_lstsize(stck) < 2)
		return (stck);
	tmp = ft_lstlast(stck);
	ft_stck_last_menos_um(stck)->next = NULL;
	tmp->next = stck;
	stck = tmp;
	return (stck);
}

t_supsta	*sup_rev_rot(t_supsta *sup)
{
	sup->a = reverse_rotater(sup->a);
	sup->b = reverse_rotater(sup->b);
	return (sup);
}
