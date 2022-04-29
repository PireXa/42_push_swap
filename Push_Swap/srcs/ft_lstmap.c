/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:24:01 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/29 10:15:01 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*nlst;
	t_stack	*temp;

	nlst = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(&lst->cnt));
		if (!temp)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, temp);
		lst = lst->next;
	}
	return (nlst);
}
