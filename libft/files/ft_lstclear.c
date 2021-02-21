/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:55:09 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/20 22:03:52 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;
	if (lst)
	{
		while (*lst)
		{
			*new = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = new;
		}
		lst = 0;
	}
}
