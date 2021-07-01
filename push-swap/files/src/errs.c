/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:05:10 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/29 14:23:15 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (1);
}

static void	check_equality(t_list **a, int e)
{
	if (e > 1)
	{
		free_lst(a);
		error_exit();
	}
}

static void	check_limit(t_list **a, char *argv[], int i)
{
	int	d;

	d = ft_atoi(argv[i]);
	if ((d == 0 && ft_strcmp(argv[i], "0"))
		|| (d == -1 && ft_strcmp(argv[i], "-1")))
	{
		free_lst(a);
		error_exit();
	}
}

void	check_errors(t_list **a, char *argv[])
{
	int	i;
	int	j;
	int	e;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		e = 0;
		while (argv[++j])
		{
			if (!ft_strcmp(argv[i], argv[j]))
				e++;
			check_equality(a, e);
		}
		check_limit(a, argv, i);
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
	}
}
