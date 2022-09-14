/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putinplace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 12:04:56 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/26 14:22:25 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	touperdido(t_supsta *sup, t_calccom *fds, int a)
{
	if (fds->rot_a < a / 2)
	{
		while (fds->rot_a && fds->rot_b)
		{
			sup = super_rotater(sup);
			fds->rot_a--;
			fds->rot_b--;
		}
		while (fds->rot_a--)
		{
			sup->a = rotater(sup->a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (a-- - fds->rot_a > 0)
		{
			sup->a = reverse_rotater(sup->a);
			ft_printf("rra\n");
		}
	}
}

void	putinrightplace(t_supsta *sup, t_calccom *fds)
{
	int	a;

	a = ft_lstsize(sup->a);
	touperdido(sup, fds, a);
	while (fds->rot_b)
	{
		sup->b = rotater(sup->b);
		ft_printf("rb\n");
		fds->rot_b--;
	}
	sup = pa(sup);
}

int	calc_e(t_stack *a, int e)
{
	int		min;
	t_stack	*fds;

	fds = a;
	min = fds->cnt;
	min = calc_min(fds, min);
	while (fds->cnt != min)
	{
		fds = fds->next;
		e++;
	}
	return (e);
}

t_stack	*putminonposition(t_stack *stack, int init)
{
	while (stack->cnt != init)
		stack = rotater(stack);
	return (stack);
}
