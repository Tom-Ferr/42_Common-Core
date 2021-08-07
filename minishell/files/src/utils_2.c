#include "minishell.h"

int	tofindmalloc(char **tofind, t_list *lst)
{
	int	i;

	i = 0;
	while (lst && !ft_iscontained(*(lst->content)," \t\"\'"))
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
	t_list	*stop;
	t_list	*zeroth_lst;

	while (temp)
	{
		lst_append(lst, *(temp->content));
		temp = temp->next;
		*lst = (*lst)->next;
	}
	stop = *lst;
	zeroth_lst = lst_rewind(*lst);
	ft_removequotes(&zeroth_lst, '\"');
	*lst = stop;
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
	while (((*lst)->next) && (*((*lst)->next->content) != '='
			|| *((*lst)->next->content) == '$'))
		lst_detach(lst);
	writevariablevalue(lst, temp);
	free_lst(&temp);
	free(tofind);
}
