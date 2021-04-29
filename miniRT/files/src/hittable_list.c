/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:21:04 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/27 18:41:24 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable_list.h"

int	ft_lstsize(t_hittable_list *lst)
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

t_hittable_list	*ft_lstnew(void *content)
{
	t_hittable_list	*newlist;

	newlist = (t_hittable_list *)malloc(sizeof(t_hittable_list));
	if (!newlist)
		return (0);
	newlist->obj = content;
	newlist->next = 0;
	return (newlist);
}

t_hittable_list	*ft_lstlast(t_hittable_list *lst)
{
	size_t	len;

	if (!lst)
		return (0);
	len = ft_lstsize(lst);
	while (--len)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_hittable_list **lst, t_hittable_list *new)
{
	t_hittable_list	*ret;

	if (!*lst)
		*lst = new;
	else
	{
		ret = ft_lstlast(*lst);
		ret->next = new;
	}
}

void	ft_freelst(t_hittable_list *lst)
{
	t_hittable_list	*new;

	while (lst->next)
	{
		new = lst->next;
		free(lst->obj->mat_ptr);
		free(lst->obj);
		free(lst);
		lst = new;
	}
	free(lst->obj->mat_ptr);
	free(lst->obj);
	free(lst);
}
