/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:25:14 by fde-albe          #+#    #+#             */
/*   Updated: 2022/05/03 11:16:54 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

typedef struct s_stacks {
	int					cnt;
	struct	s_stacks	*next;
}						t_stack;

typedef struct s_ez {
	t_stack	*a;
	t_stack *b;
	int		ctr;
}			t_ez;

typedef struct s_cenas {
	int		max;
	int     max2;
	int		min;
	int     min2;
}			t_tao_facil;

int		ft_atoi(const char *str);

void    ft_lstadd_back(t_stack **lst, t_stack *new);

void    ft_lstadd_front(t_stack **lst, t_stack *new);

void    ft_lstclear(t_stack **lst, void (*del)(void *));

void    ft_lstdelone(t_stack *lst, void (*del)(void *));

void    ft_lstiter(t_stack *lst, void (*f)(void *));

t_stack  *ft_lstlast(t_stack *lst);

t_stack  *ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));

t_stack  *ft_lstnew(int content);

int     ft_lstsize(t_stack *lst);

#endif
