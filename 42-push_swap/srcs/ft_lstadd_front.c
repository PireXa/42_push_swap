/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:10:05 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/28 15:42:28 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_lstadd_front(t_stack **stck, t_stack *novo)
{
	if (stck)
	{
		if (*stck)
			novo->next = *stck;
		*stck = novo;
	}
}
