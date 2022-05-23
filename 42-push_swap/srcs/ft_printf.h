/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:46:29 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/03/08 13:39:05 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdarg.h>
# include<stdio.h>

typedef struct s_print_
{
	va_list	args;
	int		lentot;
}					t_print;

size_t		ft_strlen(const char *s);

void		ft_putstr(t_print *tab);

void		ft_putchar(t_print *tab);

void		ft_puthex(t_print *tab, char formater);

char		*ft_strupcase(char *str);

void		ft_putptr(t_print *tab);

void		ft_putsigned(t_print *tab);

void		ft_putunsigned(t_print *tab);

void		*ft_memset(void *b, int c, size_t len);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t count, size_t size);

char		*ft_itoa(int c);

char		*ft_uitoa(unsigned int c);

int			ft_printf(const char *str, ...);

#endif
