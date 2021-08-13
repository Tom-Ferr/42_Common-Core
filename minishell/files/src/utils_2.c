/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*   By: nfranco- <nfranco-@student.42.fr>        +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:58:13 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:38:25 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tofindmalloc(char **tofind, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && !ft_iscontained(*(lst->content), " \t\"\'|\376"))
	{
		lst = lst->next;
		i++;
	}
	*tofind = (char *)malloc(i + 2);
	return (i);
}

void	searchvalue(char **tofind, t_list *lst, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		(*tofind)[j] = *(lst->content);
		lst = lst->next;
		j++;
	}
	(*tofind)[j] = '=';
	(*tofind)[j + 1] = '\0';
}

void	pickvariable(t_list *env, t_list **temp, char *tofind, int i)
{
	char	**found;

	found = NULL;
	while (env)
	{
		if (ft_strncmp(env->content, tofind, i + 1) == 0)
		{
			env_exp_prep_util(env, '=', -4);
			found = ft_split(env->content, -4);
			env_exp_prep_util(env, -4, '=');
			break ;
		}
		env = env->next;
	}
	*temp = 0;
	if (!found || found[1] == NULL)
		argtolst("\b", temp);
	else
		argtolst(found[1], temp);
	if (found)
		free_star(found);
}

void	writevariablevalue(t_list **lst, t_list *temp)
{
	while (temp)
	{
		if (*(temp->content) == '|')
			*(temp->content) = -4;
		lst_append(lst, *(temp->content));
		temp = temp->next;
		*lst = (*lst)->next;
	}
}

void	ft_convertdollartovalue(t_list **lst, t_list *env)
{
	char	*tofind;
	int		i;
	t_list	*temp;

	*lst = (*lst)->next;
	i = tofindmalloc(&tofind, *lst);
	searchvalue(&tofind, *lst, i);
	pickvariable(env, &temp, tofind, i);
	*lst = (*lst)->prev->prev;
	while (((*lst)->next) && (i-- + 1 != 0))
		lst_detach(lst);
	writevariablevalue(lst, temp);
	free_lst(&temp);
	free(tofind);
}
