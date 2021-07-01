/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 09:42:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/01 07:47:32 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc < 2)
		return (0);
	i = argc;
	while (--i)
		if (!ft_isdigit(argv[i]) && (*argv[i] != '-'))
			error_exit();
	a = NULL;
	check_errors(&a, argv);
	b = NULL;
	test_input(&a, &b);
	if (a && (is_row(a, UP, &i) && (ft_lstsize(a) == (argc - 1))))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (b)
		free_lst(&a);
	if (b)
		free_lst(&b);
	return (0);
}
