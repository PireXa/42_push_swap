/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:15:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/23 16:25:09 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_stacks(t_stack *stck_a, t_stack *stck_b)
{
	while (stck_a || stck_b)
	{
		if (stck_a)
			ft_printf("%d", stck_a->cnt);
		ft_printf("      ");
		if (stck_b)
			ft_printf("%d\n", stck_b->cnt);
		else
			ft_printf("\n");
		if (stck_a)
			stck_a = stck_a->next;
		if (stck_b)
			stck_b = stck_b->next;
	}
	ft_printf("-      -\na      b\n");
	ft_printf("################\n");
}

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

t_stack *putminonstart(t_stack *stack)
{
	int min;

	min = stack->cnt;
	min = calc_min(stack, min);
	while (stack->cnt != min)
	{
		stack = rotater(stack);
		ft_printf("ra\n");
	}
	return (stack);
}

int	check_same(int *lst, int rando, int max)
{
	int	i = -1;
	while (++i < max)
		if (rando == lst[i])
			return (1);
	return (0);
}

t_supsta	*gen_gator(t_supsta *sup, char *size, char *big)
{
	int	i = -1;
	int	nb = atoi(size);
	int	cap = atoi(big);
	int	max = nb;
	int	rando = 0;
	int	sign;
	int	lst[nb];
	sup->elenum = 0;
	srand(time(0));
	while (++i < max)
	{
		sign = rand()%2;
		if (sign == 0)
			sign = -1;
		rando = rand()%cap * sign;
		while (check_same(lst, rando, i))
			rando = rand()%cap * sign;
		lst[i] = rando;
		ft_lstadd_back(&sup->a, ft_lstnew(rando));
		sup->elenum++;
	}
	return (sup);
}

int	main(int ac, char **av)
{
	t_supsta	*sup;
	
	(void)ac;
	sup = malloc(sizeof(t_supsta));
	if (!sup)
		exit(0);
//	sup = input_reader(ac, av, sup);
	sup = gen_gator(sup, av[1], av[2]);
//	print_stacks(sup->a, sup->b);
	if (ac == 3)
	{
		if (sup->a->next->cnt < sup->a->cnt)
		{
			swap(sup->a);
			ft_printf("sa\n");
		}
		exit(0);
	}
	sup->a = putminonstart(sup->a);

	int *arr;
	arr = malloc(sizeof(int) * sup->elenum);
	input_to_arr(arr, sup);
	notlis_gob(sup, arr);

	t_calccom	*fds;

	fds = (t_calccom *)malloc(sizeof(t_calccom));
//	print_stacks(sup->a, sup->b);
	while (sup->b != NULL)
	{
		fds = get_fastest_nb(sup, fds);
		putinrightplace(sup, fds);
	}
	
	sup->a = putminonstart(sup->a);
//	print_stacks(sup->a, sup->b);
	exit(0);
}
