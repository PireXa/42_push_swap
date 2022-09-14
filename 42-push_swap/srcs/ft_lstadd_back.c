/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:50:51 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/28 16:28:27 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_lstadd_back(t_stack **stck, t_stack *new)
{
	t_stack	*last_node;

	if (!*stck)
	{
		ft_lstadd_front(stck, new);
		return ;
	}
	last_node = ft_lstlast(*stck);
	last_node->next = new;
}

/*int main()
{
	t_list lst = [["adwdawd"],["wadawd"],["dawd"]];
	t_list *new = ft_lstnew(ft_strdup("OK"));
	ft_lstadd_back(lst, new);
}*/
