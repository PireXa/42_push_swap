/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:56:34 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/10 11:54:51 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_newstrlen(unsigned int temp)
{
	int	i;

	i = 0;
	while (temp > 15)
	{
		temp /= 16;
		i++;
	}
	return (i);
}

void	ft_puthex(t_print *tab, char formater)
{
	unsigned long	n;
	char			*a;
	int				i;
	unsigned long	temp;

	i = 0;
	n = va_arg(tab->args, long);
	temp = n;
	i = ft_newstrlen(temp);
	a = (char *)ft_calloc(i + 1, sizeof(char *));
	while (n >= 0 && i >= 0)
	{
		a[i--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	if (formater == 'X')
		a = ft_strupcase(a);
	tab->lentot += write(1, a, ft_strlen(a));
	free(a);
}
