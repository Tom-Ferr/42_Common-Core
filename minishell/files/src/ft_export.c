#include "minishell.h"

void	free_star(char **me)
{
	int	i;

	i = 0;
	while (me[i])
	{
		free(me[i]);
		i++;
	}
	if (me[i])
		free(me[i]);
	free(me);
}

void	copy_env(char *env[])
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_lstadd_back(&g_main.env, ft_lstnew(ft_strdup(env[i])));
		i++;
	}
}

int	lookforvariable(char **arg, char *argv[], t_list **env, int i)
{
	int		found;

	found = 0;
	while (*env)
	{
		if (!ft_strncmp((*env)->content, arg[0], ft_strlen(arg[0])))
		{
			if (arg[1])
			{
				free((*env)->content);
				(*env)->content = ft_strdup(argv[i]);
			}
			(*env)->visible = 1;
			found = 1;
			return (found);
		}
		*env = (*env)->next;
	}
	return (found);
}

int	ft_export(int argc, char *argv[], t_list **env)
{
	int		i;
	int		found;
	char	**arg;
	t_list	*zeroth;

	i = 0;
	if (!ft_strcmp(argv[0], "export"))
		i = 1;
	found = 0;
	zeroth = *env;
	while (i < argc)
	{
		arg = ft_split(argv[i], '=');
		found = lookforvariable(arg, argv, env, i);
		*env = zeroth;
		if (found == 0)
			ft_lstadd_back(env, ft_lstnew(ft_strdup(argv[i])));
		if (found == 0 && !ft_strrchr(argv[i], '='))
			ft_lstlast(*env)->visible = 0;
		i++;
		argc--;
		free_star(arg);
	}
	return (0);
}
