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
			if (!ft_strncmp((*env)->content, argv[i],
					ft_strlen_tilchar((*env)->content, '='))
				&& !ft_strncmp(argv[i], (*env)->content,
					ft_strlen(argv[i])))
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
	int	exit_val;

	if (argc > 2)
	{
		errno = E2BIG;
		return (1);
	}
	if (argv[1])
		exit_val = ft_atoi(argv[1]);
	if (argc != 1 && !exit_val && *argv[1] != 48)
	{
		write(1, "Numeric argument required.\n", 27);
		exit_val = 255;
	}
	if (argc == 1)
		exit_val = 0;
	write(1, "exit\n", 5);
	free_lst(&g_main.buff);
	free_lst(&g_main.env);
	free_star(argv);
	*env = NULL;
	close(g_main.fd_hist);
	init_term(true);
	exit(exit_val);
	return (0);
}
