#include "minishell.h"

void	inputupdate(char **arg, int i)
{
	if (arg[i][1] == arg[i][0])
	{
		if (arg[i][0] == '<')
			g_main.parse.input.quote = 1;
		else
			g_main.parse.output.quote = 1;
	}
	else
	{
		if (arg[i][0] == '<')
			g_main.parse.input.quote = 0;
		else
			g_main.parse.output.quote = 0;
	}
}

void	inputfile_checker(char **arg, char **input, int i)
{
	if (arg[i][0] == '<')
	{
		if (g_main.parse.input.file)
			free(g_main.parse.input.file);
		g_main.parse.input.file = ft_strdup(input[1]);
	}
	else
	{
		if (g_main.parse.output.file)
			free(g_main.parse.output.file);
		g_main.parse.output.file = ft_strdup(input[1]);
	}
}

char	**inputhandler(char **arg)
{
	int		i;
	int		j;
	char	**input;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (ft_iscontained(arg[i][0], "><") == 1)
		{
			inputupdate(arg, i);
			if (ft_strchr(arg[i], ' ') == 1)
				input = ft_split(arg[i], ' ');
			else
				input = ft_split(arg[i], arg[i][0]);
			inputfile_checker(arg, input, i);
			j++;
			free_star(input);
		}
		i++;
	}
	return ((char **)malloc(((i - j) + 1) * sizeof(char **)));
}

int	cmd_handling(char ***temp, char ***arg)
{
	int		i;
	int		j;

	*temp = inputhandler(*arg);
	i = 0;
	j = 0;
	while ((*arg)[i])
	{
		if (ft_iscontained((*arg)[i][0], "><") == 1)
			i++;
		else
		{
			(*temp)[j] = ft_strdup((*arg)[i]);
			j++;
			i++;
		}
	}
	(*temp)[j] = NULL;
	if (!(*temp)[0])
		return (free_star(*temp), 1);
	i = 0;
	if (j != 1)
		while (i < (j - 1))
			(*temp)[0] = ft_strjoin((*temp)[0], (*temp)[++i], ' ');
	return (0);
}

int	ft_parsing(char *live)
{
	char	**arg;
	char	**temp;
	int		k;
	int		check;

	k = 0;
	check = 0;
	check = parsing_prep(live);
	if (check)
		return (check);
	while (g_main.parse.cmd[k])
	{
		pipe_reverse(g_main.parse.cmd[k]);
		arg = ft_split(g_main.parse.cmd[k], -1);
		if (cmd_handling(&temp, &arg))
			return (free_star(arg), 1);
		free(g_main.parse.cmd[k]);
		g_main.parse.cmd[k] = ft_strdup(temp[0]);
		free(temp[0]);
		free(temp);
		free_star(arg);
		k++;
	}
	return (0);
}
