/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/31 16:17:10 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_supsta *sup)
{
	int	i;
	int	max;

	i = 1;
	sup->a = rotater(sup->a, 0);
	max = sup->a->cnt;
	max = calc_max(sup->a, max);
	while (i < sup->elenum)
	{
		if (sup->a->cnt != max)
			sup = pb(sup);
		else
			sup->a = rotater(sup->a, 0);
		i++;
	}
}

void	putinrightplace(t_supsta *sup, t_calccom *fds)
{
	int	a;

	a = ft_lstsize(sup->a);
	if (fds->rot_a < a / 2)
	{
		while (fds->rot_a && fds->rot_b)
		{
			sup = super_rotater(sup);
			fds->rot_a--;
			fds->rot_b--;
		}
		while (fds->rot_a--)
			sup->a = rotater(sup->a, 0);
	}
	else
		while (a-- - fds->rot_a > 0)
			sup->a = reverse_rotater(sup->a);
	while (fds->rot_b--)
		sup->b = rotater(sup->b, 1);
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
