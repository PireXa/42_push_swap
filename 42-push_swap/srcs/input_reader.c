/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:19:35 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/31 15:28:55 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include "libft.h"

static void	error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

static void	check_same(t_stack *stck)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ft_lstsize(stck) - 1)
	{
		while (j < ft_lstsize(stck))
		{
			if (ft_lstindex(i, stck)->cnt == ft_lstindex(j, stck)->cnt)
				error_message();
			j++;
		}
		i++;
		j = i + 1;
	}
	return ;
}

static void	error_input_check(int ac, char **av)
{
	int		i;
	int		j;
	char	**inp;

	i = 1;
	j = 0;
	if (ac < 2)
		exit(0);
	while (i < ac)
	{
		inp = (char **)malloc(strcount(av[i], 32) * (sizeof(char *) + 1));
		inp = ft_split(av[i], 32, inp);
		while (inp[j])
		{
			if (!is_number(inp[j]))
				error_message();
			else if (ft_atoi(inp[j]) > INT_MAX || ft_atoi(inp[j]) < INT_MIN)
				error_message();
			free(inp[j]);
			j++;
		}
		j = 0;
		i++;
		free(inp);
	}
}

t_supsta	*input_reader(int ac, char **av, t_supsta *sup)
{
	int		*arr;
	char	**inputs;

	arr = (int [2]){0, 0};
	sup->elenum = 1;
	error_input_check(ac, av);
	while (++arr[0] < ac)
	{
		inputs = ft_calloc(strcount(av[arr[0]], 32), (sizeof(char *) + 1));
		inputs = ft_split(av[arr[0]], 32, inputs);
		while (inputs[arr[1]])
		{
			ft_lstadd_back(&sup->a, ft_lstnew(ft_atoi(inputs[arr[1]])));
			free(inputs[arr[1]++]);
			sup->elenum++;
		}
		arr[1] = 0;
		free(inputs);
	}
	sup->elenum--;
	check_same(sup->a);
	if (sup->elenum == 1)
		exit(0);
	return (sup);
}

int	*input_to_arr(int *arr, t_supsta *sup)
{
	t_stack	*tmp;
	int		i;

	tmp = sup->a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->cnt;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
