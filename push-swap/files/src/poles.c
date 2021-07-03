/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:05:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/01 23:15:28 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	find_poles(t_list *lst)
{
	long	sum;

	sum = 0;
	while (lst)
	{
		sum += lst->content;
		lst = lst->next;
	}
	return (sum);
}

void	polarize(t_list *lst)
{
	int	div;

	div = find_poles(lst) / ft_lstsize(lst);
	while (lst)
	{
		if (lst->content <= div)
			lst->pole = 1;
		else
			lst->pole = 0;
		lst = lst->next;
	}
}

static void	mini_sort(t_list **a, t_list **b, t_pole info, int full)
{
	int		i;
	int		size;

	size = full - info.count - 1;
	while (size)
	{
		if (is_row(*a, UP, &i) && !*b)
			return ;
		if ((*a)->content > (*a)->next->content)
			ft_swap(a, NULL);
		else if (i < full / 2)
			ft_rotate(a, NULL);
		else
			ft_rev_rotate(a, NULL);
	}
}

static void	throw(t_list **a, t_list **b, t_pole info, int full)
{
	int		i;
	int		size;

	size = full - info.count - 1;
	while (size)
	{
		if (is_row(*a, UP, &i) && !*b)
			return ;
		if ((*a)->select >= 0)
		{
			ft_push(a, b, true);
			size--;
		}
		else if (i <= full / 2)
			ft_rotate(a, NULL);
		else
			ft_rev_rotate(a, NULL);
		if (full > 5)
			if (*b)
				if ((*b)->pole == 0)
					ft_rotate(NULL, b);
	}
}

void	repeal(t_list **a, t_list **b, t_pole info)
{
	int		size;

	size = ft_lstsize(*a);
	if (size < 5)
	{
		mini_sort(a, b, info, size);
		return ;
	}
	else
		throw(a, b, info, size);
}
