/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:18:54 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/14 17:56:42 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newlist;

	newlist = (t_list *)malloc(sizeof(t_list));
	if (!newlist)
		return (0);
	newlist->content = content;
	newlist->next = 0;
	return (newlist);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ret;

	if (!*lst)
		*lst = new;
	else
	{
		ret = ft_lstlast(*lst);
		ret->next = new;
		ret->next->next = 0;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	size_t	len;

	if (!lst)
		return (0);
	len = ft_lstsize(lst);
	while (--len)
		lst = lst->next;
	return (lst);
}
