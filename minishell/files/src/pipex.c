#include "minishell.h"

void	last_child_util(int *file)
{
	if (g_main.parse.input.quote)
	{
		*file = open("/tmp/temp_file.tmp", O_CREAT | O_TRUNC | O_WRONLY,
				S_IRWXU);
		if (*file < 0)
		{
			printf("Error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		ft_heredoc(file);
	}
	else
		*file = open(g_main.parse.input.file, O_RDONLY);
}

static void	last_child(int fd[], char *argv[], char *envp[])
{
	int		file;

	if (g_main.parse.input.file)
		last_child_util(&file);
	else
		file = STDIN_FILENO;
	if (file < 0)
	{
		printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	dup2(file, 0);
	flow_pipe(1, fd, argv[0], envp);
}

static void	child(int fd[], int jr, char *argv[], char *envp[])
{
	int		id;
	int		xd[2];

	if (jr)
	{
		pipe(xd);
		id = fork();
		if (id == 0)
		{
			child(xd, jr - 1, argv, envp);
			close(xd[0]);
			close(xd[1]);
		}
		else
		{
			close(xd[1]);
			wait(NULL);
			dup2(xd[0], 0);
			close(xd[0]);
			flow_pipe(1, fd, argv[jr - 1], envp);
		}
	}
	else
		last_child(fd, argv, envp);
}

static void	parent(int fd[], int argc, char *argv[], char *envp[])
{
	int	file;

	wait(NULL);
	if (g_main.parse.output.file)
	{
		if (g_main.parse.output.quote)
			file = open(g_main.parse.output.file, O_CREAT | O_WRONLY | O_APPEND,
					S_IRUSR | S_IWUSR);
		else
			file = open(g_main.parse.output.file, O_CREAT | O_WRONLY | O_TRUNC,
					S_IRUSR | S_IWUSR);
	}
	else
		file = STDOUT_FILENO;
	if (file < 0)
		printf("Error: %s\n", strerror(errno));
	dup2(file, 1);
	flow_pipe(0, fd, argv[argc], envp);
}

int	ft_exec(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		id;

	if (pipe(fd) < 0)
		printf("Error: %s\n", strerror(errno));
	id = 42;
	if (g_main.parse.input.file || g_main.parse.pipe)
		id = fork();
	if (id < 0)
		printf("Error: %s\n", strerror(errno));
	else if (id == 0)
		child(fd, argc, argv, envp);
	else
		parent(fd, argc, argv, envp);
	return (0);
}
