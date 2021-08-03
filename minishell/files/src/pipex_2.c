#include "minishell.h"

void	flow_pipe(int x, int fd[], char *argv, char *envp[])
{
	char	**cmd;

	cmd_spacereverse(&argv);
	cmd = ft_split(argv, -2);
	close(fd[1 - x]);
	if (g_main.parse.output.file || g_main.parse.pipe
		|| g_main.parse.input.file)
		dup2(fd[x], x);
	close(fd[x]);
	ft_searchbuiltins(cmd, envp);
	if (!ft_strrchr(cmd[0], '/'))
		set_path(&cmd, envp);
	execve(cmd[0], cmd, envp);
	free_star(cmd);
	write(2, "Error: Command not found\n", 25);
	exit(1);
}

void	set_path(char **cmd[], char *env[])
{
	int				i;
	char			**path;
	char			**target;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i])
	{
		path = ft_split(env[i], '=');
		target = ft_split(path[1], ':');
		free_star(path);
		ft_whereis(cmd, target);
		free_star(target);
	}
}

void	ft_builtinsfound(
							int (*f)(int argc,
							char *argv[],
							char *env[]),
							int argc,
							char *argv[],
							char *env[]
						)
{
	if (!f(argc, argv, env))
	{
		free_star(argv);
		exit (EXIT_SUCCESS);
	}
	else
	{
		free_star(argv);
		printf("Error: %s\n", strerror(errno));
		exit (EXIT_FAILURE);
	}
}

int	ft_countlines(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

void	ft_searchbuiltins(char	**cmd, char *env[])
{
	int	(*f)(int argc, char *argv[], char *env[]);
	int	line_count;

	f = NULL;
	line_count = ft_countlines(cmd);
	if ((ft_strcmp(cmd[0], "echo") == 0))
		f = ft_echo;
	else if ((ft_strcmp(cmd[0], "env") == 0))
		f = ft_env;
	else if ((ft_strcmp(cmd[0], "pwd") == 0))
		f = ft_pwd;
	if (f != NULL)
		ft_builtinsfound(f, line_count, cmd, env);
}
