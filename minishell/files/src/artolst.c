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
			if (*((*lst)->next->content) == *((*lst)->content))
				*lst = (*lst)->next;
			if (ft_iscontained(*((*lst)->next->content), " \t"))
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

int	token_handle(t_list **lst, int *setted)
{
	if ((ft_iscontained(*((*lst)->content), "><")
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
	return (0);
}

int	interpreter(t_list **lst)
{
	int setted;

	setted = 0;
	while (*lst)
	{
		if (ft_checkquotes(lst) == 0)
			break ;
		if (interpreter_util(lst, &setted))
			return (256);
		while (*((*lst)->content) == '|'
			&& ft_iscontained(*((*lst)->next->content), " \t"))
			lst_detach(lst);
		if (((*lst)->next) && ((*lst)->next->next)
			&& ft_iscontained(*((*lst)->next->content), " \t")
			&& *((*lst)->next->next->content) == '|')
			lst_detach(lst);
		*lst = (*lst)->next;
	}
	return (0);
}
