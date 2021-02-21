/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:00:40 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/16 00:47:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*endcleaning(t_list **p, void (*del)(void *))
{
	ft_lstclear(p, del);
	return (0);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*prev;
	t_list	*ret;

	if (!lst)
		return (0);
	new = 0;
	prev = 0;
	while (lst)
	{
		if (!new)
		{
			ret = ft_lstnew(f(lst->content));
			new = ret;
		}
		else
			new = ft_lstnew(f(lst->content));
		if (!new)
			return (endcleaning(&new, del));
		if (prev)
			ft_lstadd_back(&prev, new);
		prev = new;
		lst = lst->next;
	}
	return (ret);
}
