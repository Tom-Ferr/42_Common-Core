#include "minishell.h"

void	run_util(char **visible_env)
{
	if (g_main.id == 0)
	{
		init_term(true);
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		ft_exec(g_main.parse.pipe, g_main.parse.cmd, visible_env);
	}
	else
	{
		signal(SIGINT, &sig_handle_child);
		signal(SIGQUIT, &sig_handle_child);
		wait(&g_main.exitval);
		init_term(false);
		g_main.exitval = WEXITSTATUS(g_main.exitval);
	}
}

void	parsing_error_handler(int checker)
{
	if (checker == 258)
	{
		write(2, "syntax error near token\n", 24);
		g_main.exitval = 258;
	}
	else
	{
		if (g_main.parse.cmd)
			free_star(g_main.parse.cmd);
		g_main.parse.cmd = NULL;
	}
}

void	ft_run(void)
{
	char	**visible_env;
	int		checker;

	g_main.parse.cmd = NULL;
	visible_env = ft_envarray(g_main.env);
	checker = ft_parsing(g_main.live);
	if (checker != 0)
		parsing_error_handler(checker);
	if (g_main.parse.cmd)
		ft_otherbuiltins(g_main.parse.cmd);
	if (g_main.parse.cmd && g_main.parse.cmd[0])
	{
		g_main.id = fork();
		run_util(visible_env);
	}
	free_star(visible_env);
	if (g_main.parse.cmd)
		free_star(g_main.parse.cmd);
	if (g_main.parse.input.file)
		free(g_main.parse.input.file);
	if (g_main.parse.output.file)
		free(g_main.parse.output.file);
}
