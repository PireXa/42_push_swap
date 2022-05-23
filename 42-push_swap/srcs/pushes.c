/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:08:21 by fde-albe          #+#    #+#             */
/*   Updated: 2022/05/23 10:08:24 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_supsta	*pa(t_supsta *sup)
{
	t_stack	*tmp;

	if (sup->b == NULL)
		return (sup);
	tmp = sup->b->next;
	sup->b->next = sup->a;
	sup->a = sup->b;
	sup->b = tmp;
	return (sup);
}

t_supsta	*pb(t_supsta *sup)
{
	t_stack	*tmp;

	if (sup->a == NULL)
		return (sup);
	tmp = sup->a->next;
	sup->a->next = sup->b;
	sup->b = sup->a;
	sup->a = tmp;
	return (sup);
}
