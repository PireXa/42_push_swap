/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:51:44 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/07 13:09:14 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putstr(t_print *tab)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(tab->args, char *);
	if (s == NULL)
	{
		tab->lentot += write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	tab->lentot += i;
}	
