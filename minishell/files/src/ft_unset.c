#include "minishell.h"

int	ft_unset(int argc, char *argv[], t_list **env)
{
	int		i;
	t_list	*zeroth;

	i = 1;
	zeroth = *env;
	while (argc != 1)
	{
		while (*env)
		{
			if (!ft_strncmp((*env)->content, argv[i], ft_strlen(argv[i])))
			{
				*env = (*env)->prev;
				lst_detach(env);
				break ;
			}
			*env = (*env)->next;
		}
		i++;
		argc--;
		*env = zeroth;
	}
	return (0);
}

int	ft_exit(int argc, char *argv[], t_list **env)
{
	argc--;
	if (argv)
		argv[0] = NULL;
	write(1, "exit\n", 5);
	free_lst(&g_main.buff);
	free_lst(&g_main.env);
	*env = NULL;
	close(g_main.fd_hist);
	init_term(true);
	exit(0);
	return (0);
}
