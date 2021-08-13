/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   artolst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	argtolst(char *arr, t_list **lst)
{
	int		i;
	char	*c;

	i = -1;
	while (arr[++i])
	{
		c = (char *)malloc(1);
		*c = arr[i];
		ft_lstadd_back(lst, ft_lstnew(c));
	}
}

void	lst_append(t_list **lst, char content)
{
	t_list	*new;
	char	*c;

	c = (char *)malloc(1);
	*c = content;
	new = ft_lstnew(c);
	new->next = (*lst)->next;
	if (new->next)
		new->next->prev = new;
	new->prev = (*lst);
	(*lst)->next = new;
}

void	lst_detach(t_list **lst)
{
	t_list	*temp;

	temp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst);
	free(temp->content);
	free(temp);
}

void	lst_prep(t_list **lst)
{
	while (*lst)
	{
		if (ft_iscontained(*((*lst)->content), "><"))
		{
			if ((*lst)->prev && (ft_iscontained(*((*lst)->prev->content)
						, " \t")))
				*((*lst)->prev->content) = -1;
			if ((*lst)->next && *((*lst)->next->content) == *((*lst)->content))
				*lst = (*lst)->next;
			if ((*lst)->next && ft_iscontained(*((*lst)->next->content), " \t"))
				*lst = (*lst)->next->next;
			while (((*lst)->next) && !ft_iscontained(*((*lst)->content), " \t")
				&& ((*lst)->next) && *((*lst)->content) != '|')
				*lst = (*lst)->next;
			if (ft_iscontained(*((*lst)->content), " \t"))
				*((*lst)->content) = -1;
		}
		if ((*lst))
			*lst = (*lst)->next;
	}
}
