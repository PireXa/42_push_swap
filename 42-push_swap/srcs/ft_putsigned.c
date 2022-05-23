/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:22:48 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/07 11:26:07 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putsigned(t_print *tab)
{
	int		temp;
	char	*s;

	temp = va_arg(tab->args, int);
	s = ft_itoa(temp);
	tab->lentot += write(1, s, ft_strlen(s));
	free(s);
}
