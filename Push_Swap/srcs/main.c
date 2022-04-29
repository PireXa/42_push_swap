/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:05:09 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/29 17:24:17 by fde-albe         ###   ########.fr       */
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

void	super_sortata(t_ez *sup)
{
	int ctr = 0;
	int b = ft_lstsize(sup->a);
	int	tao_facil = 0;
	while (ft_lstsize(sup->a) > 1)
	{
		while (b > 1)
		{
			if (tao_facil < sup->a->cnt)
				tao_facil = sup->a->cnt;
			sup->a = rotater(sup->a);
			ctr++;
			b--;
		}
		b = ft_lstsize(sup->a);
		while (b > 1)
		{
			if (tao_facil == sup->a->cnt)
			{
				sup = pb(sup);
				ctr++;
				b = ft_lstsize(sup->a);
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
	printf("%d\n", ctr);
	print_stacks(sup->a, sup->b);
}

int main(int ac, char **av)
{
	int	i = 0;
	int	nb = 0;
	t_ez *sup;

	sup = malloc(sizeof(t_ez));
//	ft_lstadd_front(&sup->a, ft_lstnew(0));
//	ft_lstadd_front(&sup->a, ft_lstnew(0));
	while (++i < ac)
	{
		nb = ft_atoi(av[i]);
		ft_lstadd_back(&sup->a, ft_lstnew(nb));
	}
	print_stacks(sup->a, sup->b);
/*	print_stacks(sup->a, sup->b);
	sup->a = rotater(sup->a);
	print_stacks(sup->a, sup->b);
	sup->a = reverse_rotater(sup->a);
	print_stacks(sup->a, sup->b);*/
	super_sortata(sup);
	free(sup);
	exit(0);
}
