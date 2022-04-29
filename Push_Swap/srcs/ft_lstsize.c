/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:26:04 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/27 10:49:12 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	temp;

	temp.next = lst;
	i = 0;
	while (temp.next != NULL)
	{
		i++;
		temp.next = temp.next -> next;
	}
	return (i);
}
