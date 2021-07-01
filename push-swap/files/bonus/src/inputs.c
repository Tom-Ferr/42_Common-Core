/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:05:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/29 15:42:02 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	is_row(t_list *lst, int dir, int *i)
{
	int	size;

	size = ft_lstsize(lst);
	*i = 0;
	while (lst->next)
	{
		if (((lst->content - lst->next->content) * dir) > 0)
			break ;
		lst = lst->next;
		*i = *i + 1;
	}
	if (!lst->next)
		*i = size;
	return (lst->next == NULL);
}

static void	free_err(t_list **a, t_list **b)
{
	free_lst(a);
	free_lst(b);
	error_exit();
}

static void	get_input(t_list **a, t_list **b, char *line)
{
	if (!ft_strcmp(line, "ss"))
		ft_swap(a, b);
	else if (!ft_strcmp(line, "sa"))
		ft_swap(a, NULL);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(NULL, b);
	else if (!ft_strcmp(line, "rr"))
		ft_rotate(a, b);
	else if (!ft_strcmp(line, "ra"))
		ft_rotate(a, NULL);
	else if (!ft_strcmp(line, "rb"))
		ft_rotate(NULL, b);
	else if (!ft_strcmp(line, "rrr"))
		ft_rev_rotate(a, b);
	else if (!ft_strcmp(line, "rra"))
		ft_rev_rotate(a, NULL);
	else if (!ft_strcmp(line, "rrb"))
		ft_rev_rotate(NULL, b);
	else if (!ft_strcmp(line, "pa"))
		ft_push(b, a);
	else if (!ft_strcmp(line, "pb"))
		ft_push(a, b);
	else
		free_err(a, b);
}

void	test_input(t_list **a, t_list **b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		get_input(a, b, line);
		free(line);
	}
	free(line);
}
