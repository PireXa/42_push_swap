/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:05:09 by fde-albe          #+#    #+#             */
/*   Updated: 2022/05/02 11:20:03 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stacks(t_stack *stck_a, t_stack *stck_b);

t_ez	*pb(t_ez *sup)
{
	t_stack *tmp;

	tmp = sup->a->next;
	sup->a->next = sup->b;
	sup->b = sup->a;
	sup->a = tmp;
	return (sup);
}

t_stack *ft_lst_bef_last(t_stack *stck)
{
	t_stack *temp;

	if (!stck)
		return (NULL);
	temp = stck;
	while (temp->next->next != NULL)
		temp = temp->next;
	return (temp);
}

t_stack	*rotater(t_stack *stck)
{
	t_stack	*tmp;

	tmp = stck->next;
	stck->next = NULL;
	ft_lstlast(tmp)->next = stck;
	stck = tmp;
	return(stck);
}

t_stack	*reverse_rotater(t_stack *stck)
{
	t_stack	*tmp;

	tmp = ft_lstlast(stck);
	ft_lst_bef_last(stck)->next = NULL;
	tmp->next = stck;
	stck = tmp;
	return(stck);
}

void	print_stacks(t_stack *stck_a, t_stack *stck_b)
{
	while (stck_a || stck_b)
	{
		if (stck_a)
			printf("%d    ", stck_a->cnt);
		else
			printf("     ");
		if (stck_b)
			printf("%d\n", stck_b->cnt);
		else
			printf("\n");
		if (stck_a)
			stck_a = stck_a->next;
		if (stck_b)
			stck_b = stck_b->next;
	}
	printf("################\n");
}

int	calc_max(t_stack *stack)
{
	t_stack	*ex;
	int	max = 0;

	ex = stack;
	while (ex)
	{
		if (ex->cnt > max)
			max = ex->cnt;
		ex = ex->next;
	}
	return (max);
}

void	super_sortata(t_ez *sup)
{
	int ctr = 0;
	int b = ft_lstsize(sup->a);
	int	tao_facil = 0;
	while (b > 1)
	{
	/*	while (b)
		{
			if (tao_facil < sup->a->cnt)
				tao_facil = sup->a->cnt;
			sup->a = rotater(sup->a);
			ctr++;
			b--;
		}
		b = ft_lstsize(sup->a);*/
		tao_facil = calc_max(sup->a);
		while (b)
		{
			if (sup->a->cnt == tao_facil)
			{
				sup = pb(sup);
				ctr++;
				break;
			}
			else
			{
				sup->a = rotater(sup->a);
				ctr++;
				b--;
			}
		}
		tao_facil = 0;
		b = ft_lstsize(sup->a);
	}
	sup = pb(sup);
	ctr++;
	printf("%d\n", ctr);
	printf("################\n");
//	print_stacks(sup->a, sup->b);
}

int	check_same(int *lst, int rando, int max)
{
	int	i = -1;

	while (++i < max)
		if (rando == lst[i])
			return (1);
	return (0);
}

t_stack	*gen_gator(t_stack *a)
{
	int	i = -1;
	int	max = 100;
	int	rando = 0;
	int	lst[100];
	srand(time(0));
	while (++i < max)
	{
		rando = rand()%700;
		while (check_same(lst, rando, i))
			rando = rand()%700;
		lst[i] = rando;
		ft_lstadd_back(&a, ft_lstnew(rando));
	}
	return (a);
}

int main(int ac, char **av)
{
//	int	i = 0;
//	int	nb = 0;
	t_ez *sup;

	(void)ac;
	(void)av;
	sup = malloc(sizeof(t_ez));
	sup->a = gen_gator(sup->a);
/*	while (++i < ac)
	{
		nb = ft_atoi(av[i]);
		ft_lstadd_back(&sup->a, ft_lstnew(nb));
	}
	print_stacks(sup->a, sup->b);
	print_stacks(sup->a, sup->b);
	sup->a = rotater(sup->a);
	print_stacks(sup->a, sup->b);
	sup->a = reverse_rotater(sup->a);
	print_stacks(sup->a, sup->b);*/
	super_sortata(sup);
	free(sup);
	exit(0);
}
