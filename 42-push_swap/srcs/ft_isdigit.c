/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:15:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/05 13:47:55 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

bool	is_number(char number[])
{
	int	i;

	i = 0;
	if (number[0] == '-')
		i = 1;
	while (number[i] != 0)
	{
		if (!ft_isdigit(number[i]))
			return (false);
		i++;
	}
	return (true);
}
