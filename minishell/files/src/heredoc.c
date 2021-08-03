#include "minishell.h"

int	check_input_here(int file)
{
	if (g_main.input[0] > 31 || g_main.input[0] == '\t')
		str_update(g_main.live, g_main.input[0], &(g_main.i));
	else if (g_main.input[0] == '\e' && g_main.input[1] == '[')
		arrow_keys();
	else if (g_main.input[0] == CTRL_L)
		clear("> ");
	else if (g_main.input[0] == '\n')
	{
		if (!ft_strcmp(g_main.live, g_main.parse.input.file))
			return (1);
		write(file, g_main.live, ft_strlen(g_main.live));
		write(file, "\n", 1);
		write(1, "\n", 1);
		newline("> ");
	}
	return (0);
}

void	ft_heredoc(int *file)
{
	int	del;

	del = 0;
	init_term(false);
	newline("> ");
	write(1, CURSOR_SAVE, 3);
	while (!del)
	{
		read(0, g_main.input, 3);
		if (g_main.input[0] == CTRL_D && !g_main.live[0])
		{
			write(1, "warning: here-document delimited by end-of-file", 47);
			break ;
		}
		else
			del = check_input_here(*file);
	}
	write(1, "\n", 1);
	init_term(true);
	close(*file);
	*file = open("/tmp/temp_file.tmp", O_RDONLY);
}
