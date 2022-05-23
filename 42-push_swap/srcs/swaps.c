/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:16 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/05 13:40:42 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_stack *st)
{
	int	hold;

	if (ft_lstsize(st) < 2)
		return ;
	hold = st->cnt;
	st->cnt = ft_lstindex(1, st)->cnt;
	ft_lstindex(1, st)->cnt = hold;
}

void	super_swaper(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
