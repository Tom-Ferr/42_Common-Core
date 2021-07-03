/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ft_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:54:06 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/02 12:24:25 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	stack_swap(t_list **x)
{
	t_list	tmp;

	if (!*x || ft_lstsize(*x) < 2)
		return ;
	tmp = **x;
	(*x)->content = (*x)->next->content;
	(*x)->pole = (*x)->next->pole;
	(*x)->next->content = tmp.content;
	(*x)->next->pole = tmp.pole;
}

void	ft_swap(t_list **a, t_list **b)
{
	if (a)
		stack_swap(a);
	if (b)
		stack_swap(b);
}

void	ft_push(t_list **x, t_list **y)
{
	t_list	*tmp;

	if (!*x)
		return ;
	tmp = *x;
	*x = tmp->next;
	if (!*y)
		tmp->next = 0;
	else
		tmp->next = *y;
	*y = tmp;
}
