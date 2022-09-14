/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:31:39 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/31 15:58:45 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	calc_min(t_stack *stack, int min)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (min > tmp->cnt)
			min = tmp->cnt;
		tmp = tmp->next;
	}
	return (min);
}

int	calc_max(t_stack *stack, int max)
{
	t_stack	*tmp;

	tmp = stack;
	max = tmp->cnt;
	while (tmp)
	{
		if (max < tmp->cnt)
			max = tmp->cnt;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*putminonstart(t_stack *stack, int size)
{
	int		min;
	int		i;
	int		a;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	min = stack->cnt;
	min = calc_min(stack, min);
	while (tmp->cnt != min)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size / 2)
	{
		while (i-- > 0)
			stack = rotater(stack, 0);
		return (stack);
	}
	a = size - i;
	while (a-- > 0)
		stack = reverse_rotater(stack);
	return (stack);
}

t_stack	*putmaxonstart(t_stack *stack, int size)
{
	int		max;
	int		i;
	int		a;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	max = stack->cnt;
	max = calc_max(stack, max);
	while (tmp->cnt != max)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size / 2)
	{
		while (i-- > 0)
			stack = rotater(stack, 0);
		return (stack);
	}
	a = size - i;
	while (a-- > 0)
		stack = reverse_rotater(stack);
	return (stack);
}
