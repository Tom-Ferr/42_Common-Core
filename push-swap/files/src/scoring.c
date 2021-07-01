/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:05:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/29 18:29:27 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_extreme(t_list *a, int dir)
{
	int	i;
	int	ret;
	int	extreme;

	i = 0;
	ret = i;
	extreme = a->content;
	while (a)
	{
		if (((a->content - extreme) * dir) > 0)
		{
			ret = i;
			extreme = a->content;
		}
		i++;
		a = a->next;
	}
	return (ret);
}

static	int	cross_stack(t_list *stack, int dir, t_list *cross)
{
	int		i;
	t_list	*last;
	t_list	*zeroth;
	bool	one;

	i = 0;
	zeroth = cross;
	last = ft_lstlast(cross);
	one = false;
	while (cross)
	{
		if (((last->content - stack->content) * dir) > 0)
			one = true;
		if (one)
			if (((cross->content - stack->content) * (dir * -1)) > 0)
				break ;
		i++;
		last = cross;
		cross = cross->next;
	}
	if (!one && (dir == 1))
		return (-1);
	if (!one)
		return (find_extreme(zeroth, dir));
	return (i);
}

static	int	calc_score(int i, int j, int size_a, int size_b)
{
	if (i < 0)
		i = size_b - (i * -1);
	if (j < 0)
		j = size_a - (j * -1);
	return (i + j + 1);
}

static	int	make_score(t_list *shooter, t_list *target, int dir, int j)
{
	int	size_a;
	int	size_b;
	int	low_score;

	size_a = ft_lstsize(shooter);
	size_b = ft_lstsize(target);
	low_score = size_a + size_b;
	while (shooter)
	{
		shooter->j = j;
		if (j > (size_a / 2))
			shooter->j *= -1;
		shooter->i = cross_stack(shooter, dir, target);
		if (shooter->i < 0)
			shooter->i = 0;
		else if (shooter->i > (size_b / 2))
			shooter->i *= -1;
		shooter->score = calc_score(shooter->i, shooter->j, size_a, size_b);
		if (shooter->score < low_score)
			low_score = shooter->score;
		j++;
		shooter = shooter->next;
	}
	return (low_score);
}

int	get_score(t_list *a, t_list *b, t_list **win)
{
	int	score_a;
	int	score_b;
	int	score;

	score_b = make_score(b, a, DOWN, 0);
	score_a = score_b + 1;
	if (score_a < score_b)
	{
		*win = a;
		score = score_a;
	}
	else
	{
		*win = b;
		score = score_b;
	}
	return (score);
}
