#include "minishell.h"

void	ft_removequotes(t_list **lst, char target)
{
	while (*lst)
	{
		if (((*lst)->next) && *((*lst)->next->content) == target)
			lst_detach(lst);
		*lst = (*lst)->next;
	}
}

void	singlequotes(bool quote, t_list **lst)
{
	t_list	*zeroth;
	t_list	*continued;

	zeroth = (*lst)->prev;
	while (((*lst)->next) && *lst && quote)
	{
		*lst = (*lst)->next;
		if (ft_iscontained(*((*lst)->content), " \t"))
			*((*lst)->content) = -2;
		if (ft_iscontained(*((*lst)->content), "'"))
			quote = 0;
	}
	continued = (*lst)->next;
	*lst = zeroth;
	if (quote == 0)
		g_main.parse.quotes = 1;
	ft_removequotes(lst, '\'');
	*lst = continued;
}

void	doublequotes(bool quote, t_list **lst)
{
	t_list	*zeroth;
	t_list	*continued;

	zeroth = (*lst)->prev;
	while (((*lst)->next) && *lst && quote)
	{
		*lst = (*lst)->next;
		if (ft_iscontained(*((*lst)->content), "$"))
		{
			if (((*lst)->next) && *((*lst)->next->content) == '?')
				ft_exitvalue(lst);
			else if (((*lst)->next) && ft_isalpha(*((*lst)->next->content)))
				ft_convertdollartovalue(lst, g_main.env);
		}
		if (ft_iscontained(*((*lst)->content), " \t"))
			*((*lst)->content) = -2;
		if (ft_iscontained(*((*lst)->content), "\""))
			quote = 0;
	}
	continued = (*lst)->next;
	*lst = zeroth;
	if (quote == 0)
		g_main.parse.quotes = 2;
	ft_removequotes(lst, '\"');
	*lst = continued;
}

int	ft_checkquotes(t_list **lst)
{
	if (ft_iscontained(*((*lst)->content), "'"))
		singlequotes(true, lst);
	else if (ft_iscontained(*((*lst)->content), "\""))
		doublequotes(true, lst);
	if ((*lst))
		return (1);
	else
		return (0);
}
