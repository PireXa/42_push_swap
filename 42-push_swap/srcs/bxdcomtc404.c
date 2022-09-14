/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bxdcomtc404.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:18:43 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/27 15:54:27 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static t_bxd_tc404	*a_initializer(t_bxd_tc404 *a, t_supsta *sup)
{
	a->t = sup;
	a->temp2 = sup;
	a->d->i = 0;
	a->d->e = 0;
	a->d->rec = 236746;
	a->d->max = 0;
	a->d->initval = a->t->a->cnt;
	a->f = 1;
	a->size = ft_lstsize(sup->b);
	a->d->max = calc_max(a->t->a, a->d->max);
	return (a);
}

static t_bxd_tc404	*a_reseter(t_bxd_tc404 *a)
{
	a->f = 1;
	a->d->i++;
	a->d->e = 0;
	a->t->a = putminonposition(a->t->a, a->d->initval);
	a->temp2->a = putminonposition(a->temp2->a, a->d->initval);
	a->t->b = rotater(a->t->b);
	return (a);
}

static	t_bxd_tc404	*epaya(t_bxd_tc404 *a)
{
	a->d->e = calc_e(a->t->a, a->d->e);
	a->f = 0;
	return (a);
}

static	void	normi_ty(t_bxd_tc404 *a)
{
	free(a->d);
	free(a);
}

t_calccom	*get_fastest_nb(t_supsta *sup, t_calccom *cmds)
{
	t_bxd_tc404	*a;

	a = ft_calloc(sizeof(t_bxd_tc404), 1);
	a->d = ft_calloc(sizeof(t_buejeitodiler), 1);
	a = a_initializer(a, sup);
	while (a->d->i < a->size)
	{
		if (a->t->b->cnt > a->d->max)
			a = epaya(a);
		while ((a->t->a->cnt < a->t->b->cnt || l(a->t->a)->cnt > a->t->b->cnt)
			&& a->f)
		{
			a->t->a = rotater(a->t->a);
			a->d->e++;
		}
		if (a->d->rec > a->d->e + a->d->i)
		{
			cmds->rot_a = a->d->e;
			a->d->rec = a->d->e + a->d->i;
			cmds->rot_b = a->d->i;
		}
		a = a_reseter(a);
	}
	normi_ty(a);
	return (cmds);
}
