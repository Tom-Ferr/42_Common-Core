/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequenza.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:05:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/30 10:45:32 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_sequence(t_list *lst, int count, t_list *zeroth)
{
	t_list	*check;
	int		min;

	check = lst->next;
	if (!check)
		check = zeroth;
	min = lst->content;
	while (check != lst)
	{
		if (check->content >= min && check->content)
		{
			min = check->content;
			count++;
			check->select = -1;
			lst->select = -1;
		}
		check = check->next;
		if (!check)
			check = zeroth;
	}
	return (count);
}

static int	sequence(t_list *lst, t_pole *info)
{
	int		count;
	int		longest;
	int		ret;
	t_list	*zeroth;

	zeroth = lst;
	longest = 0;
	while (lst)
	{
		count = find_sequence(lst, 0, zeroth);
		if (count > longest)
		{
			ret = lst->content;
			longest = count;
		}
		if (lst->content > info->highest)
			info->highest = lst->content;
		if (lst->content < info->lowest)
			info->lowest = lst->content;
		lst = lst->next;
	}
	return (ret);
}

static void	reset(t_list *lst)
{
	while (lst)
	{
		lst->select = 0;
		lst = lst->next;
	}
}

void	filter(t_list *lst, t_pole *info)
{
	int		target;
	t_list	*zeroth;

	zeroth = lst;
	target = sequence(lst, info);
	polarize(lst);
	reset(lst);
	while (lst->content != target)
		lst = lst->next;
	info->count = find_sequence(lst, 0, zeroth);
}
