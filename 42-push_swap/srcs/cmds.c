/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:13:58 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/31 16:15:49 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*putminonposition(t_stack *stack, int init)
{
	while (stack->cnt != init)
		stack = rotater(stack, 2);
	return (stack);
}

static t_buejeitodeseler	*initializer(t_buejeitodeseler *d, t_supsta *sup)
{
	d->i = 0;
	d->e = 0;
	d->rec = 236746;
	d->max = 0;
	d->t = sup;
	d->temp2 = sup;
	d->initval = d->t->a->cnt;
	d->max = calc_max(d->t->a, d->max);
	d->flag = 1;
	return (d);
}

static	t_buejeitodeseler	*reset(t_buejeitodeseler *d)
{
	d->flag = 1;
	d->i++;
	d->e = 0;
	d->t->a = putminonposition(d->t->a, d->initval);
	d->temp2->a = putminonposition(d->temp2->a, d->initval);
	d->t->b = rotater(d->t->b, 2);
	return (d);
}

static t_calccom	*do_the_while(t_buejeitodeseler *d, t_calccom *cmds, int s)
{
	while (d->i < s)
	{
		if (d->t->b->cnt > d->max)
		{
			d->e = calc_e(d->t->a, d->e);
			d->flag = 0;
		}
		while ((d->t->a->cnt < d->t->b->cnt
				|| l_indx(d->t->a)->cnt > d->t->b->cnt) && d->flag)
		{
			d->t->a = rotater(d->t->a, 2);
			d->e++;
		}
		if (d->rec > d->e + d->i)
		{
			cmds->rot_a = d->e;
			d->rec = d->e + d->i;
			cmds->rot_b = d->i;
		}
		d = reset(d);
	}
	return (cmds);
}

t_calccom	*get_fastest_nb(t_supsta *sup, t_calccom *cmds)
{
	t_buejeitodeseler	*d;
	int					s;

	d = malloc(sizeof(t_buejeitodeseler));
	s = ft_lstsize(sup->b);
	d = initializer(d, sup);
	cmds = do_the_while(d, cmds, s);
	free(d);
	return (cmds);
}
