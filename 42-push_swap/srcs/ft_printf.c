/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:27:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/05 16:06:25 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static t_print	*ft_initialise_tab(t_print *tab)
{
	tab->lentot = 0;
	return (tab);
}

static void	ft_format(char formater, t_print *tab)
{
	if (formater == 'c')
		ft_putchar(tab);
	else if (formater == 's')
		ft_putstr(tab);
	else if (formater == 'p')
		ft_putptr(tab);
	else if (formater == 'd' || formater == 'i')
		ft_putsigned(tab);
	else if (formater == 'u')
		ft_putunsigned(tab);
	else if (formater == 'x' || formater == 'X')
		ft_puthex(tab, formater);
	else if (formater == '%')
		tab->lentot += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_print	*tab;
	int		ret;

	i = 0;
	ret = 0;
	tab = (t_print *)ft_calloc(1, sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_format(str[++i], tab);
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(tab->args);
	ret += tab->lentot;
	free(tab);
	return (ret);
}
