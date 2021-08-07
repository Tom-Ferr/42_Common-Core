#include "minishell.h"

int	ft_pipe(t_list *lst)
{
	int		i;
	bool	quote;
	char	which_one;

	i = 0;
	quote = 0;
	which_one = 0;
	while (lst)
	{
		if (*(lst->content) == '|' && !quote)
			i++;
		if (ft_iscontained(*(lst->content), "\'\"") && !quote)
		{
			quote = 1;
			which_one = *(lst->content);
			lst = lst->next;
			continue ;
		}
		if (*(lst->content) == which_one)
			quote = (quote + 1) % 2;
		if (*(lst->content) == '|' && quote)
			*(lst->content) = -4;
		lst = lst->next;
	}
	return (i);
}

void	pipe_reverse(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == -4)
			cmd[i] = '|';
		i++;
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
