#include "minishell.h"

void	whereis_util(struct dirent **sd, DIR **dir, char *target[], int j)
{
	*dir = opendir(target[j]);
	if (*dir)
		*sd = readdir(*dir);
	else
		*sd = NULL;
}

static void	ft_whereis(char **cmd[], char *target[])
{
	DIR				*dir;
	struct dirent	*sd;
	int				j;

	j = 0;
	while (target[j])
	{
		whereis_util(&sd, &dir, target, j);
		while (sd)
		{
			while (sd && ft_strcmp(sd->d_name, (*cmd)[0]))
				sd = readdir(dir);
			if (sd)
			{
				free((*cmd)[0]);
				(*cmd)[0] = ft_strjoin(ft_strdup(target[j]),
						ft_strdup(sd->d_name), '/');
				closedir(dir);
				return ;
			}
		}
		if (dir)
			closedir(dir);
		j++;
	}
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
		perror("Error");
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
