/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:35:48 by tde-cama          #+#    #+#             */
/*   Updated: 2021/07/13 14:52:25 by tde-cama         ###   ########.fr       */
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

# define UP "\e[A"
# define DOWN "\e[B"
# define RIGHT "\e[C"
# define LEFT "\e[D"
# define CLEAR_SCREEN "\e[2J"
# define CLEAR_LINE "\e[2K"
# define CURSOR_HOME "\e[H"
# define CTRL_C 3
# define CTRL_D 4
# define CTRL_L 12

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_info
{
	char	input[4];
	char	*live;
	int		fd_hist;
	t_list	*buff;
	size_t	i;
	size_t	j;
}			t_info;

t_info g_main;

void	*ft_calloc(size_t nblock, size_t size);
char	*ft_strdup(const char *str);

void 	get_history(char *live, t_list **buff);
void 	load_history(char **live, t_list *lst, int j);

void 	newline(t_list **buff, char *live, size_t *i, int *j);

void 	str_expans(char *live, int i, size_t stop);
void 	str_retract(char *live, size_t i);
void	str_update(char *live, char new, size_t *i);

t_list	*ft_lstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_lst(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif
