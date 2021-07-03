/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:42:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/02 12:36:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve_ring(t_list **a, t_list **b, t_pole info, int full)
{
	int	i;
	int	size_b;

	while (ft_lstsize(*a) > 2)
	{
		is_row(*a, DOWN, &i);
		if (((*a)->content != info.highest) || ((*a)->content != info.lowest))
			ft_push(a, b, true);
		else if (i <= full / 2)
			ft_rotate(a, NULL);
		else
			ft_rev_rotate(a, NULL);
		if (*b && (ft_lstsize(*b) > 1))
			ft_rotate(NULL, b);
	}
	size_b = ft_lstsize(*b);
	while (ft_lstsize(*a) == size_b)
	{
		if ((*a)->content < (*a)->next->content)
			ft_swap(a, NULL);
		else
			ft_push(b, a, false);
	}
	ft_rev_rotate(a, NULL);
}

static void	sort(t_list **a, t_list **b, t_pole *info)
{
	int	i;
	int	sizea;
	int	size;

	sizea = ft_lstsize(*a);
	size = ft_lstsize(*b) + sizea;
	while (ft_lstsize(*a) != size)
	{
		set_op(a, b, info);
		if (info->fa == info->fb)
			info->fa(a, b);
		else
		{
			info->fa(a, NULL);
			info->fb(NULL, b);
		}
	}
	while (!is_row(*a, UP, &i))
		if (i >= size / 2)
			ft_rev_rotate(a, NULL);
	else
		ft_rotate(a, NULL);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;
	t_pole	info;

	if (argc < 2)
		return (0);
	i = argc;
	while (--i)
		if (!ft_isdigit(argv[i]) && (*argv[i] != '-'))
			error_exit();
	a = NULL;
	check_errors(&a, argv);
	if (argc <= 2)
		return (0);
	filter(a, &info);
	b = NULL;
	if (is_ring(a, DOWN) && (argc - 1) > 3)
		solve_ring(&a, &b, info, ft_lstsize(a));
	else
		repeal(&a, &b, info);
	sort(&a, &b, &info);
	free_lst(&a);
	return (0);
}
