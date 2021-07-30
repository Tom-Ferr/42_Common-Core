#include "minishell.h"

static void	free_params(char const *s1, char const *s2)
{
	free((void *)s1);
	free((void *)s2);
}

char	*ft_strjoin(char const *s1, char const *s2, char sp)
{
	size_t		size;
	char		*ptr;
	char		*s1_0;
	char		*s2_0;
	char		*ptr_0;

	s1_0 = (char *)s1;
	s2_0 = (char *)s2;
	size = (ft_strlen(s1) + ft_strlen(s2)) + 2;
	ptr = (char *)malloc(size);
	if (!ptr)
		return (0);
	ptr_0 = ptr;
	while (*s1)
		*ptr++ = *s1++;
	if (sp)
		*ptr++ = sp;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free_params(s1_0, s2_0);
	return (ptr_0);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_calloc((ft_strlen(s1) + 1), sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}

int	ft_iscontained(char a, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

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
			if (arg[i][0] == '<')
				g_main.parse.input.file = ft_strdup(input[1]);
			else
				g_main.parse.output.file = ft_strdup(input[1]);
			j++;
			free_star(input);
		}
		i++;
	}
	return ((char **)malloc(((i - j) + 1) * sizeof(char **)));
}

void	cmd_handling(char ***temp, char ***arg)
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
	i = 0;
	if (j != 1)
		while (i < (j - 1))
			(*temp)[0] = ft_strjoin((*temp)[0], (*temp)[++i], ' ');
}

int	parsing_prep(char *live)
{
	t_list	*lst;
	t_list	*zeroth;
	char	*str;

	lst = NULL;
	argtolst(live, &lst);
	g_main.parse.pipe = ft_pipe(lst);
	g_main.parse.quotes = 0;
	g_main.parse.input.file = NULL;
	g_main.parse.output.file = NULL;
	ft_skeepspaces(&lst);
	zeroth = lst;
	if (!*(lst->content))
		return (free_lst(&lst), 1);
	if (interpreter(&lst))
		return (free_lst(&lst), 258);
	lst = zeroth;
	ft_checkdollarsign(&lst);
	lst = zeroth;
	lst_prep(&lst);
	lst = zeroth;
	str = lsttostr(lst);
	free_lst(&lst);
	g_main.parse.cmd = ft_split(str, '|');
	return(free(str), 0);
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
		cmd_handling(&temp, &arg);
		free(g_main.parse.cmd[k]);
		g_main.parse.cmd[k] = ft_strdup(temp[0]);
		free(temp[0]);
		free(temp);
		free_star(arg);
		k++;
	}
	return (0);
}
