/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:05:09 by fde-albe          #+#    #+#             */
/*   Updated: 2022/05/12 11:10:52 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stacks(t_stack *stck_a, t_stack *stck_b);

t_ez	*pb(t_ez *sup)
{
	t_stack *tmp;

	if (sup->a == NULL)
		return (sup);
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

	if (!stck || ft_lstsize(stck) < 2)
		return (stck);
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

t_tao_facil	*calc_max(t_stack *stack, t_tao_facil *meh)
{
	t_stack	*ex;

	ex = stack;
	meh->max = ex->cnt;
	meh->min = ex->cnt;
//	meh->max2 = ex->cnt;
//	meh->min2 = ex->cnt;
	while (ex)
	{
		if (meh->max < ex->cnt)
			meh->max = ex->cnt;
		if (meh->min > ex->cnt)
			meh->min = ex->cnt;
		ex = ex->next;
	}
	return (meh);
}

void	copy_array(int *streak_hold_rec, int *streak_test, int max)
{
	int i = -1;

	while (++i < max)
		streak_hold_rec[i] = streak_test[i];
}

void	facil(t_ez *sup)
{
	sup->ctr = 0;
	t_tao_facil *meh;
	t_stack	*sovai;
	meh = (t_tao_facil *)malloc(sizeof(t_tao_facil));
	meh = calc_max(sup->a, meh);
	int	*streak;
	int	i = -1;
	int	lst_size = ft_lstsize(sup->a);
	print_stacks(sup->a, sup->b);
	while (sup->a->cnt != meh->min)
	{
		sup->a = rotater(sup->a);
		sup->ctr++;
	}
	print_stacks(sup->a, sup->b);
	sovai = sup->a;
	streak = (int *)malloc(sizeof(int) * lst_size);
	while (sovai)
	{
		streak[++i] = sovai->cnt;
		sovai = sovai->next;
	}
	i = 0;
	while (i < lst_size)
		printf("%d\n", streak[i++]);

//Get Longest Increasing Sequence on the List

	i = 1;
	int	e = 2;
	int	f = 2;
	int	streak_record = 2;
	int	streak_count = 2;
	int	streak_hold = 0;
	int	*streak_test;
	int *streak_hold_rec;
	streak_hold_rec = (int *)malloc(sizeof(int) * (lst_size / 2));
	streak_hold_rec[0] = streak[0];
	while (i < lst_size)
	{
		streak_test = (int *)malloc(sizeof(int) * (lst_size / 2));
		streak_test[0] = streak[0];
		streak_test[1] = streak[i];
		streak_hold = streak[i];
		while (e < lst_size)
		{
			if (streak[e] > streak_hold)
			{
				streak_count++;
				streak_hold = streak[e];
				streak_test[f] = streak_hold;
				f++;
			}
			e++;
		}
		if (streak_count > streak_record)
		{
			streak_record = streak_count;
			copy_array(streak_hold_rec, streak_test, streak_record);
		}
		free(streak_test);
		streak_count = 2;
		i++;
		e = i + 1;
	}
	printf("long streak = %d\n", streak_record);
	printf("################\n");
	i = 0;
	while (i < streak_record)
		printf("%d\n", streak_hold_rec[i++]);

	free(meh);
	free(streak);
}

//Sort List

void	super_sortata(t_ez *sup)
{
	sup->ctr = 0;
	int b = ft_lstsize(sup->a);
	t_tao_facil *meh;
	meh = (t_tao_facil *)malloc(sizeof(t_tao_facil));
	meh = calc_max(sup->a, meh);
	int segura = meh->min;
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
		meh = calc_max(sup->a, meh);
//		printf("max = %d\nmin = %d\nmax2 = %d\nmin2 = %d\n", meh->max, meh->min, meh->max2, meh->min2);
//		printf("%d\n", b);
		while (b)
		{
			if (sup->a->cnt == meh->max)
			{
				sup = pb(sup);
				sup->ctr++;
				break;
			}
			else if (sup->a->cnt == meh->min)
			{
				sup = pb(sup);
				sup->b = rotater(sup->b);
				sup->ctr += 2;
				break;
			}
			sup->a = rotater(sup->a);
			sup->ctr++;
			b--;
		}
		meh->max = 0;
		b = ft_lstsize(sup->a);
	}
	sup = pb(sup);
	sup->ctr++;
	while (sup->b->cnt != segura)
	{
		sup->b = rotater(sup->b);
		sup->ctr++;
	}
	printf("%d\n", sup->ctr);
	printf("################\n");
	print_stacks(sup->a, sup->b);
	free (meh);
}

//Generate Input Numbers

int	check_same(int *lst, int rando, int max)
{
	int	i = -1;

	while (++i < max)
		if (rando == lst[i])
			return (1);
	return (0);
}

t_stack	*gen_gator(t_stack *a, char *size)
{
	int	i = -1;
	int	nb = atoi(size);
	int	max = nb;
	int	rando = 0;
	int	lst[nb];
	srand(time(0));
	while (++i < max)
	{
		rando = rand()%100;
		while (check_same(lst, rando, i))
			rando = rand()%100;
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
	sup->a = gen_gator(sup->a, av[1]);
//	super_sortata(sup);
	facil(sup);
	free(sup);
	exit(0);
}
