/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvmnts_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:45:33 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/02 11:18:22 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	mvmnts_tester(t_supsta *sup)
{
	ft_printf("Initial stage.\n");
	print_stacks(sup->a, sup->b);

	ft_printf("Swap a.\n");
	swap(sup->a);
	print_stacks(sup->a, sup->b);

	ft_printf("3x push b.\n");
	sup = pb(sup);
	sup = pb(sup);
	sup = pb(sup);
	print_stacks(sup->a, sup->b);

	ft_printf("Swap b.\n");
	swap(sup->b);
	print_stacks(sup->a, sup->b);

	ft_printf("Double swap.\n");
	super_swaper(sup->a, sup->b);
	print_stacks(sup->a, sup->b);

	ft_printf("3x push b 1 push a.\n");
	sup = pb(sup);
	sup = pb(sup);
	sup = pb(sup);
	sup = pa(sup);
	print_stacks(sup->a, sup->b);

	ft_printf("rotate a | rotate b.\n");
	sup->a = rotater(sup->a);
	sup->b = rotater(sup->b);
	print_stacks(sup->a, sup->b);

	ft_printf("super rotater.\n");
	sup = super_rotater(sup);
	print_stacks(sup->a, sup->b);

	ft_printf("reverse_rotater a and b.\n");
	sup->a = reverse_rotater(sup->a);
	sup->b = reverse_rotater(sup->b);
	print_stacks(sup->a, sup->b);

	ft_printf("sup_rev_rot.\n");
	sup = sup_rev_rot(sup);
	print_stacks(sup->a, sup->b);
}
