#include "minishell.h"

void	cmd_spacereverse(char **cmd)
{
	int		i;

	i = 0;
	while ((*cmd)[i])
	{
		if ((*cmd)[i] == -2)
			(*cmd)[i] = ' ';
		else if (ft_iscontained((*cmd)[i], " \t"))
			(*cmd)[i] = -2;
		i++;
	}
}

char	*ft_search_env(char *arg, t_list *env)
{
	char	**sp;
	char	*ret;

	ret = NULL;
	while (env)
	{
		if (!ft_strncmp(env->content, arg, ft_strlen(arg)))
		{
			sp = ft_split(env->content, '=');
			ret = ft_strdup(sp[1]);
			free_star(sp);
			return (ret);
		}
		env = env->next;
	}
	return (ret);
}

void	sig_handle_child(int signus)
{
	if (signus == SIGINT)
	{
		kill(g_main.id, SIGINT);
		write(1, "\n", 1);
	}
	else if (signus == SIGQUIT)
	{
		kill(g_main.id, SIGQUIT);
		printf("Quit\n");
	}
}
