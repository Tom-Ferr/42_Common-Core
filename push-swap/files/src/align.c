/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:05:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/30 15:02:19 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

bool	is_ring(t_list *lst, int dir)
{
	t_list	*zeroth;
	t_list	*check;
	t_list	*ith;

	zeroth = lst;
	while (lst)
	{
		ith = lst;
		check = ith->next;
		if (!check)
			check = zeroth;
		while (check != ith)
		{
			if (((ith->content - check->content) * dir) > 0)
				break ;
			ith = check;
			check = check->next;
			if (!check)
				check = zeroth;
		}
		if (check == lst)
			return (true);
		lst = lst->next;
	}
	return (false);
}

static void	ready_push(t_list **a, t_list **b, t_pole *info)
{
	ft_push(b, a, false);
	info->fa = ft_ignore;
	info->fb = ft_ignore;
}

static t_list	*find_win(t_list *win, int score)
{
	while (win && win->score != score)
		win = win->next;
	return (win);
}

void	set_op(t_list **a, t_list **b, t_pole *info)
{
	int		score;
	t_list	*win;
	void	(**flos)(t_list **a, t_list **b);
	void	(**fwin)(t_list **a, t_list **b);

	score = get_score(*a, *b, &win);
	fwin = &(info->fa);
	flos = &(info->fb);
	if (win == *b)
		fwin = &(info->fb);
	if (win == *b)
		flos = &(info->fa);
	*flos = ft_ignore;
	*fwin = ft_ignore;
	win = find_win(win, score);
	if (win->i < 0)
		*flos = ft_rev_rotate;
	else if (win->i > 0)
		*flos = ft_rotate;
	if (win->j < 0)
		*fwin = ft_rev_rotate;
	else if (win->j > 0)
		*fwin = ft_rotate;
	if (score == 1)
		ready_push(a, b, info);
}
