#include "minishell.h"

t_list	*lst_rewind(t_list *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	ft_checkdollarsign(t_list	**lst)
{
	while (*lst)
	{
		if ((*lst)->prev && ft_iscontained(*((*lst)->content), "$"))
		{
			if (((*lst)->next) && *((*lst)->next->content) == '?')
				ft_exitvalue(lst);
			else if (g_main.parse.quotes != 1 && (*lst)->next
				&& ft_isalpha(*((*lst)->next->content)))
				ft_convertdollartovalue(lst, g_main.env);
		}
		*lst = (*lst)->next;
	}
}

static void	run_otherbuiltins(
			char ***cmd_brkdown,
			int line_count,
			int (*f)(int argc, char *argv[], t_list **env)
			)
{
	if (f != NULL)
	{
		ft_firstcmdoff();
		if (f(line_count, *cmd_brkdown, &g_main.env))
		{
			printf("Error: %s\n", strerror(errno));
			g_main.exitval = 1;
		}
		else
			g_main.exitval = 0;
		if (ft_strrchr((*cmd_brkdown)[0], '='))
			ft_lstlast(g_main.env)->visible = 0;
	}
}

void	ft_otherbuiltins(char	**cmd)
{
	int		(*f)(int argc, char *argv[], t_list **env);
	int		line_count;
	char	**cmd_brkdown;

	cmd_brkdown = ft_split(cmd[0], ' ');
	line_count = ft_countlines(cmd_brkdown);
	f = NULL;
	if ((ft_strcmp(cmd_brkdown[0], "export") == 0)
		|| ft_strrchr(cmd_brkdown[0], '='))
		f = ft_export;
	else if ((ft_strcmp(cmd_brkdown[0], "unset") == 0))
		f = ft_unset;
	else if ((ft_strcmp(cmd_brkdown[0], "exit") == 0))
		f = ft_exit;
	else if ((ft_strcmp(cmd_brkdown[0], "cd") == 0))
		f = ft_cd;
	run_otherbuiltins(&cmd_brkdown, line_count, f);
	free_star(cmd_brkdown);
}

void	ft_firstcmdoff(void)
{
	int	i;

	free(g_main.parse.cmd[0]);
	i = 0;
	while (g_main.parse.cmd[i])
	{
		g_main.parse.cmd[i] = g_main.parse.cmd[i + 1];
		i++;
	}
}
