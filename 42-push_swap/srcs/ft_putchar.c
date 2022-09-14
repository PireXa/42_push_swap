/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:46:45 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/04 15:02:31 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putchar(t_print *tab)
{
	unsigned char	a;

	a = (unsigned char)(va_arg(tab->args, int));
	tab->lentot += (write(1, &a, 1));
}
