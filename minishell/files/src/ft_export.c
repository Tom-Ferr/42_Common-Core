#include "minishell.h"

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
		if (!ft_strncmp((*env)->content, arg[0],
				ft_strlen_tilchar((*env)->content, '=')))
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

void	env_exp_prep_util(t_list *env_exp, char old, char new)
{
	char	*zero_line;

	while (env_exp)
	{
		zero_line = env_exp->content;
		while (*(env_exp->content) != old)
			(env_exp->content) += 1;
		*(env_exp->content) = new;
		env_exp->content = zero_line;
		env_exp = env_exp->next;
	}
}

void	env_exp_prep(t_list *env_exp)
{
	t_list	*zeroth;
	char	**str;
	char	*new_env;

	zeroth = env_exp;
	env_exp_prep_util(env_exp, '=', -4);
	while (env_exp)
	{
		str = ft_split(env_exp->content, -4);
		new_env = ft_strjoin(ft_strdup("declare -x "), str[0], 0);
		new_env = ft_strjoin(new_env, ft_strdup("=\""), 0);
		new_env = ft_strjoin(new_env, str[1], 0);
		new_env = ft_strjoin(new_env, ft_strdup("\""), 0);
		if (env_exp->visible)
		{
			write(1, new_env, ft_strlen(new_env));
			write(1, "\n", 1);
		}
		free(str);
		free(new_env);
		env_exp = env_exp->next;
	}
	env_exp = zeroth;
	env_exp_prep_util(env_exp, -4, '=');
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
		free_star(arg);
	}
	if (argc == 1 && !ft_strrchr(argv[0], '='))
		env_exp_prep(*env);
	return (0);
}
