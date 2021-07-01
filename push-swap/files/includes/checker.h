/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:09:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/29 14:31:18 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "get_next_line.h"

# define  UP 1
# define  DOWN -1

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				pole;
}					t_list;

void	ft_swap(t_list **a, t_list **b);
void	ft_push(t_list **x, t_list **y);
void	ft_rotate(t_list **a, t_list **b);
void	ft_rev_rotate(t_list **a, t_list **b);

int		error_exit(void);
bool	is_row(t_list *lst, int dir, int *i);
int		ft_atoi(const char *str);
int		ft_isdigit(char *c);
void	check_errors(t_list **a, char *argv[]);
void	free_lst(t_list **lst);
int		ft_strcmp(char *str1, char *str2);
void	test_input(t_list **a, t_list **b);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif
