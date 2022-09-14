/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:25:00 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/31 15:45:07 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static t_stack	*only_three(t_stack *stack)
{
	int	min;

	min = stack->cnt;
	min = calc_min(stack, min);
	if (ft_lstindex(0, stack)->cnt == min)
		stack = rotater(stack, 0);
	else if (ft_lstindex(1, stack)->cnt == min)
		stack = reverse_rotater(stack);
	if (ft_lstindex(0, stack)->cnt > ft_lstindex(1, stack)->cnt)
	{
		swap(stack);
		ft_printf("sa\n");
		stack = reverse_rotater(stack);
		return (stack);
	}
	stack = reverse_rotater(stack);
	return (stack);
}

static void	only_four(t_supsta *sup)
{
	sup->a = putmaxonstart(sup->a, sup->elenum);
	sup = pb(sup);
	sup->a = only_three(sup->a);
	sup = pa(sup);
	sup->a = rotater(sup->a, 0);
}

static void	only_five(t_supsta *sup)
{
	sup->a = putmaxonstart(sup->a, sup->elenum);
	sup = pb(sup);
	sup->a = putminonstart(sup->a, sup->elenum -1);
	sup = pb(sup);
	sup->a = only_three(sup->a);
	sup = pa(sup);
	sup = pa(sup);
	sup->a = rotater(sup->a, 0);
}

void	hardcoded(t_supsta *sup)
{
	if (sup->elenum == 2)
	{
		if (sup->a->next->cnt < sup->a->cnt)
		{
			swap(sup->a);
			ft_printf("sa\n");
		}
		exit(0);
	}
	if (sup->elenum == 3)
	{
		only_three(sup->a);
		exit(0);
	}
	if (sup->elenum == 4)
	{
		only_four(sup);
		exit(0);
	}
	if (sup->elenum == 5)
	{
		only_five(sup);
		exit(0);
	}
}
