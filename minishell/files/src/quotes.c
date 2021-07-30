#include "minishell.h"

void	ft_removequotes(t_list **lst, char target)
{
	while (*lst)
	{
		if (((*lst)->next) && *((*lst)->next->content) == target)
			lst_detach(lst);
		*lst = (*lst)->next;
	}
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

void	ft_skeepspaces(t_list **lst)
{
	while (ft_iscontained(*((*lst)->content), " \t"))
	{
		if (!((*lst)->next))
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("")));
		*lst = (*lst)->next;
		free((*lst)->prev->content);
		free((*lst)->prev);
		(*lst)->prev = 0;
	}
}
