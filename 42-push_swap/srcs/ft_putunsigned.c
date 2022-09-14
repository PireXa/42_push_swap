/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:22:48 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/07 13:09:46 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putunsigned(t_print *tab)
{
	unsigned int	temp;
	char			*s;

	temp = va_arg(tab->args, unsigned int);
	s = ft_uitoa(temp);
	tab->lentot += write(1, s, ft_strlen(s));
	free(s);
}
