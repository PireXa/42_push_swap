/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:41:23 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/31 14:04:41 by rdas-nev         ###   ########.fr       */
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
	return (sup);
}
