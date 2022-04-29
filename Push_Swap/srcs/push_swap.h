/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:25:14 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/29 12:39:56 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_stacks {
	int					cnt;
	struct	s_stacks	*next;
}						t_stack;

typedef struct s_ez {
	t_stack	*a;
	t_stack *b;
}			t_ez;

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
