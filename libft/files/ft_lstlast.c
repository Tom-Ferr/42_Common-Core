/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:34:30 by tde-cama          #+#    #+#             */
/*   Updated: 2021/02/15 15:11:41 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	size_t len;

	if (!lst)
		return (0);
	len = ft_lstsize(lst);
	while (--len)
		lst = lst->next;
	return (lst);
}
