/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ft_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:54:06 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/28 23:27:04 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_swap(t_list **x)
{
	t_list	tmp;

	tmp = **x;
	(*x)->content = (*x)->next->content;
	(*x)->pole = (*x)->next->pole;
	(*x)->select = (*x)->next->select;
	(*x)->next->content = tmp.content;
	(*x)->next->pole = tmp.pole;
	(*x)->next->select = tmp.select;
}

void	ft_swap(t_list **a, t_list **b)
{
	if (a)
		stack_swap(a);
	if (b)
		stack_swap(b);
	if (a && !b)
		write(1, "sa\n", 3);
	else if (b && !a)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
}

void	ft_ignore(t_list **a, t_list **b)
{
	if (a != b)
		return ;
}

void	ft_push(t_list **x, t_list **y, bool c)
{
	t_list	*tmp;

	tmp = *x;
	*x = tmp->next;
	if (!*y)
		tmp->next = 0;
	else
		tmp->next = *y;
	*y = tmp;
	if (!c)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
