/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:09:41 by tde-cama          #+#    #+#             */
/*   Updated: 2021/06/30 14:23:53 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

# define  UP 1
# define  DOWN -1

typedef struct s_list
{
	int				content;
	int				pole;
	int				select;
	int				score;
	int				i;
	int				j;
	struct s_list	*next;
}					t_list;

typedef struct s_pole
{
	int				count;
	int				highest;
	int				lowest;
	int				blank;
	void			(*fa)(t_list **a, t_list **b);
	void			(*fb)(t_list **a, t_list **b);
}					t_pole;

void	ft_swap(t_list **a, t_list **b);
void	ft_push(t_list **x, t_list **y, bool c);
void	ft_rotate(t_list **a, t_list **b);
void	ft_rev_rotate(t_list **a, t_list **b);
void	ft_ignore(t_list **a, t_list **b);

int		error_exit(void);
void	repeal(t_list **a, t_list **b, t_pole info);
void	polarize(t_list *lst);
void	filter(t_list *lst, t_pole *info);
bool	is_row(t_list *lst, int dir, int *i);
int		ft_atoi(const char *str);
int		ft_isdigit(char *c);
void	check_errors(t_list **a, char *argv[]);
void	free_lst(t_list **lst);
int		ft_strcmp(char *str1, char *str2);
void	set_op(t_list **a, t_list **b, t_pole *info);
int		get_score(t_list *a, t_list *b, t_list **win);
bool	is_ring(t_list *lst, int dir);

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

#endif
