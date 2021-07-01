/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:36:01 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/29 16:00:19 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	stack_rotate(t_list **x)
{
	t_list	tmp;
	t_list	*last;

	if (!*x)
		return ;
	if (ft_lstsize(*x) < 2)
		return ;
	tmp = **x;
	last = ft_lstlast(*x);
	last->next = *x;
	(*x)->next = 0;
	*x = tmp.next;
}

void	ft_rotate(t_list **a, t_list **b)
{
	if (a)
		stack_rotate(a);
	if (b)
		stack_rotate(b);
}

static void	stack_rev_rotate(t_list **x)
{
	t_list	*tmp;
	int		len;

	if (!*x)
		return ;
	len = ft_lstsize(*x);
	if (len < 2)
		return ;
	tmp = ft_lstlast(*x);
	ft_lstadd_front(x, tmp);
	while (--len)
		*x = (*x)->next;
	(*x)->next = 0;
	*x = tmp;
}

void	ft_rev_rotate(t_list **a, t_list **b)
{
	if (a)
		stack_rev_rotate(a);
	if (b)
		stack_rev_rotate(b);
}
