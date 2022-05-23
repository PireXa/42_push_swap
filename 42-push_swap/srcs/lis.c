/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:04:58 by fde-albe          #+#    #+#             */
/*   Updated: 2022/05/23 16:00:30 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*lis(int *v, int len, t_stack *p)
{
	int			i;
	t_stack		*n;

	p->lislen = 0;
	i = -1;
	n = ft_calloc(len, sizeof(*n));
	while (++i < len)
		n[i].cnt = v[i];
	while (i--)
	{
		p = n + i;
		while (p++ < n + len)
		{
			if (p->cnt > n[i].cnt && p->len >= n[i].len)
			{
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}
	p = n;
	while (++i < len)
		if (n[i].len > p->len)
		{
			p = n + i;
		}
	t_stack *fds = ft_calloc(len, sizeof *p);
	fds = p;
	while (fds)
	{
		p->lislen += 1;
		fds = fds->next;
	}
	return (p);
}

static int	check_if_dif_nb(int a, int b)
{
	if (a != b)
		return 1;
	return 0;
}

void	notlis_gob(t_supsta *sup, int *arr_lst)
{
	int	lst_size = sup->elenum;
	t_stack  *p;
	p = calloc(sizeof(*p), lst_size);
	p = lis(arr_lst, lst_size, p);
	int e;
	int	*arr_lis;
	int fds = p->lislen;
	arr_lis = (int *)malloc(sizeof(int) * fds);
	int i = 0;
	
	if (p->lislen == sup->elenum)
		exit(0);
	while (p->next)
	{
		arr_lis[i] = p->cnt;
		p = p->next;
		i++;
	}
	arr_lis[i] = p->cnt;
	i = 0;
	e = -1;
	while (i++ < lst_size)
	{
		while (++e < fds)
		{
			if (!check_if_dif_nb(sup->a->cnt, arr_lis[e]))
			{
				break;
			}
		}
		if (e == fds)
		{
			sup = pb(sup);
			ft_printf("pb\n");
		}
		else
		{
			sup->a = rotater(sup->a);
			ft_printf("ra\n");
		}
		e = -1;
	}
}

void	putinrightplace(t_supsta *sup, t_calccom   *fds)
{
//	printf("COISO\n");
//	printf("rot_a: %d\nrot_b: %d\n", fds->rot_a, fds->rot_b);
//	print_stacks(sup->a, sup->b);
	while (fds->rot_a && fds->rot_b)
	{
		sup = super_rotater(sup);
		ft_printf("rr\n");
		fds->rot_a--;
		fds->rot_b--;
	}
	while (fds->rot_a)
	{
		sup->a = rotater(sup->a);
		ft_printf("ra\n");
		fds->rot_a--;
	}
	while (fds->rot_b)
	{
		sup->b = rotater(sup->b);
		ft_printf("rb\n");
		fds->rot_b--;
	}
	sup = pa(sup);
	ft_printf("pa\n");
//	printf("FINAL COISO\n\n");
//	print_stacks(sup->a, sup->b);
}

int	calc_e(t_stack *a, int e)
{
	int	min;
	t_stack	*fds;

	fds = a;
	min = fds->cnt;
	min = calc_min(fds, min);
//	printf("min = %d\n\n\n\n\n\n\n\n", min);
//	print_stacks(a, a);
	while (fds->cnt != min)
	{
		fds = fds->next;
		e++;
	}
//	print_stacks(a, a);
//	printf("SAIUUUUUUUUUUUUU\n\n");
	return(e);
}

t_stack	*putminonposition(t_stack *stack, int init)
{
//	printf("PUT POSITION\n");
//	print_stacks(stack, stack);
	while (stack->cnt != init)
		stack = rotater(stack);
	return(stack);
}

t_calccom	*get_fastest_nb(t_supsta *sup, t_calccom *cmds)
{
	int			*i_e;
	int			flag;
	int			size;
	t_supsta	*test;

	test = sup;
	i_e = (int [5]){0, 0, 0, 236746, test->a->cnt}; // i, e, max, rec, initial value
	flag = 1;
	size = ft_lstsize(sup->b);
	i_e[2] = calc_max(test->a, i_e[2]);
	while (i_e[0] < size)
	{
//		printf("STACKSSSSSSSSSS\n");
//		print_stacks(test->a, test->b);
		if (test->b->cnt > i_e[2])
		{
//			printf("CARALHO PAAAAAAAAAAA\n");
			i_e[1] = calc_e(test->a, i_e[1]);
			flag = 0;
		}
//		print_stacks(test->a, test->b);
		while((test->a->cnt < test->b->cnt || ft_lastindex(test->a)->cnt > test->b->cnt) && flag)
		{
			test->a = rotater(test->a);
			i_e[1]++;
		}
//		print_stacks(test->a, test->b);
//		printf("Ver bem numero\n\n");
//		printf("rot_a: %d\nrot_b: %d\n\n\n", i_e[1], i_e[0]);
		if (i_e[3] > i_e[1] + i_e[0])
		{
			i_e[3] = i_e[1] + 1;
			cmds->rot_a = i_e[1];
			cmds->rot_b = i_e[0];
		}
		flag = 1;
		i_e[0]++;
		i_e[1] = 0;
//		print_stacks(test->a, test->b);
		test->a = putminonposition(test->a, i_e[4]);
		test->b = rotater(test->b);
	}
	return(cmds);
}
