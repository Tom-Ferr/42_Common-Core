/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:35:48 by tde-cama          #+#    #+#             */
/*   Updated: 2021/08/03 19:33:55 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "gnl.h"
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>
# include <stdbool.h>
# include <errno.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <string.h>

# define UP "\e[A"
# define DOWN "\e[B"
# define RIGHT "\e[C"
# define LEFT "\e[D"
# define CLEAR_SCREEN "\e[2J"
# define CLEAR_END "\e[J"
# define CLEAR_LINE "\e[2K"
# define CURSOR_HOME "\e[H"
# define CURSOR_SAVE "\e[s"
# define CURSOR_REST "\e[u"
# define CURSOR_GET "\e[6n"
# define CTRL_C 3
# define CTRL_D 4
# define CTRL_L 12
# define PROMPT "minishell > "

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	struct s_list	*prev;
	bool			visible;
}					t_list;

typedef struct s_io
{
	char	*file;
	int		quote;
}			t_io;

typedef struct s_parse
{
	t_io	input;
	t_io	output;
	char	**cmd;
	int		pipe;
	int		quotes;
}		t_parse;

typedef struct s_info
{
	char	input[4];
	char	*live;
	int		fd_hist;
	t_list	*buff;
	size_t	i;
	int		j;
	int		fd_env;
	t_list	*env;
	t_parse	parse;
	int		exitval;
	int		id;
	int		rows_up;
}			t_info;

t_info	g_main;

void	*ft_calloc(size_t nblock, size_t size);
char	*ft_strdup(const char *str);

void	get_history(void);
void	load_history(t_list *lst);
int		open_history(char *file);
void	init_term(bool mode);
void	check_tty(void);

void	newline(char *prompt);
void	h_keys(char *side, int u);
void	v_keys(void);
void	arrow_keys(void);
void	save_history(void);
void	clear(char *prompt);
void	check_input(void);

void	str_expans(char *live, int i, size_t stop);
void	str_retract(char *live, size_t i);
void	str_update(char *live, char new, size_t *i);

void	copy_env(char *env[]);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_export(int argc, char *argv[], t_list **env);
int		ft_unset(int argc, char *argv[], t_list **env);
int		ft_exit(int argc, char *argv[], t_list **env);
int		ft_isalpha(int c);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
char	*ft_strjoin(char const *s1, char const *s2, char sp);
int		ft_strchr(const char *s, char c);
int		ft_atoi(char *str);

int		ft_parsing(char *live);
int		parsing_prep(char *live);
int		ft_pipe(t_list *lst);
int		ft_iscontained(char a, char *set);
void	free_star(char **me);
void	lst_detach(t_list **lst);
void	lst_append(t_list **lst, char content);
char	*lsttostr(t_list *lst);
void	ft_run(void);

void	argtolst(char *arr, t_list **lst);
void	lst_prep(t_list **lst);
int		interpreter(t_list **lst);
void	ft_skeepspaces(t_list **lst);
int		ft_checkquotes(t_list **lst);
void	ft_removequotes(t_list **lst, char target);
t_list	*lst_rewind(t_list *lst);

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_lst(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	env_exp_prep(t_list *env_exp);

char	*ft_strrchr(const char *str, int c);
void	ft_searchbuiltins(char	**cmd, char *env[]);
void	ft_checkdollarsign(t_list	**lst);
void	ft_convertdollartovalue(t_list **lst, t_list *env);

int		ft_exec(int argc, char *argv[], char *envp[]);
void	set_path(char **cmd[], char *env[]);
void	ft_otherbuiltins(char	**cmd);
void	ft_exitvalue(t_list **lst);
void	ft_firstcmdoff(void);
int		ft_countlines(char **cmd);
void	flow_pipe(int x, int fd[], char *argv, char *envp[]);
void	ft_whereis(char **cmd[], char *target[]);

char	**ft_envarray(t_list *envp);
void	cmd_spacereverse(char **cmd);
char	*ft_search_env(char *arg, t_list *env);
void	pipe_reverse(char *cmd);

int		ft_cd(int argc, char *argv[], t_list **env);
int		ft_echo(int argc, char *argv[], char *env[]);
int		ft_env(int argc, char *argv[], char *env[]);
int		ft_pwd(int argc, char *argv[], char *env[]);

void	sig_handle_child(int signus);
void	sig_handle(int signus);
void	ft_heredoc(int *file);
int		ft_strlen_tilchar(char *str, char c);

void	check_lastline(char new);
char	*ft_itoa(int n);
#endif
