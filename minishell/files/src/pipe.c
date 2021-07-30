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
		if (*(lst->content) == which_one)
			quote = (quote + 1) % 2;
		if (ft_iscontained(*(lst->content), "\'\"") && !quote)
		{
			quote = 1;
			which_one = *(lst->content);
		}
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
