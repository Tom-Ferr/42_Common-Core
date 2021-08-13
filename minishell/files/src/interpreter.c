/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_handle(t_list **lst, int *setted)
{
	if (((*lst)->next) && (ft_iscontained(*((*lst)->content), "><")
			&& (!(*((*lst)->next->content) == (*((*lst)->content))
					|| (ft_iscontained(*((*lst)->next->content), " \t"))))))
		lst_append(lst, ' ');
	if (((*lst)->prev && ft_iscontained(*((*lst)->content), "><"))
		&& (!(*((*lst)->prev->content) == *((*lst)->content)
				|| ft_iscontained(*((*lst)->prev->content), " \t"))))
	{
		*lst = (*lst)->prev;
		lst_append(lst, ' ');
	}
	if (ft_iscontained(*((*lst)->content), "><")
		|| ((*setted && ft_iscontained(*((*lst)->content), " \t"))
			&& (!(*((*lst)->next->content) == (*((*lst)->content))))))
		*setted += 1;
	if (*setted > 2 && ft_iscontained(*((*lst)->content), "><"))
		return (256);
	if (*setted && !ft_iscontained(*((*lst)->content), " \t><"))
		*setted = 0;
	return (0);
}

int	interpreter_util(t_list **lst, int *setted)
{
	if (token_handle(lst, setted))
		return (256);
	if (((*lst)->next) && ((*lst)->next->next)
		&& ft_iscontained(*((*lst)->content), " \t")
		&& ft_iscontained(*((*lst)->next->content), " \t"))
	{
		lst_detach(lst);
		*lst = (*lst)->prev;
	}
	while (((*((*lst)->content) == '|' && (*lst)->next))
		&& ft_iscontained(*((*lst)->next->content), " \t"))
		lst_detach(lst);
	return (0);
}

int	interpreter(t_list **lst)
{
	int		setted;
	t_list	*zeroth;

	setted = 0;
	zeroth = *lst;
	while (*lst)
	{
		if (ft_checkquotes(lst) == 0 && g_main.parse.pipe == 0)
			break ;
		if (interpreter_util(lst, &setted))
			return (*lst = zeroth, 256);
		if (((*lst)->next) && ((*lst)->next->next)
			&& ft_iscontained(*((*lst)->next->content), " \t")
			&& *((*lst)->next->next->content) == '|')
			lst_detach(lst);
		if (*((*lst)->content) == '|' && (!(*lst)->prev || !(*lst)->next))
			return (*lst = zeroth, 256);
		*lst = (*lst)->next;
	}
	if (setted)
		return (*lst = zeroth, 256);
	else
		return (0);
}

int	parsing_prep(char *live)
{
	t_list	*lst;
	t_list	*zeroth;
	char	*str;

	lst = NULL;
	argtolst(live, &lst);
	g_main.parse.pipe = ft_pipe(lst);
	g_main.parse.quotes = 0;
	g_main.parse.input.file = NULL;
	g_main.parse.output.file = NULL;
	ft_skeepspaces(&lst);
	zeroth = lst;
	if (!*(lst->content))
		return (free_lst(&lst), 1);
	if (interpreter(&lst))
		return (free_lst(&lst), 258);
	lst = zeroth;
	ft_checkdollarsign(&lst);
	lst = zeroth;
	lst_prep(&lst);
	lst = zeroth;
	str = lsttostr(lst);
	free_lst(&lst);
	g_main.parse.cmd = ft_split(str, '|');
	return (free(str), 0);
}
