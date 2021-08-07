#include "minishell.h"

char	*lsttostr(t_list *lst)
{
	int		size;
	char	*ret;

	size = ft_lstsize(lst);
	ret = (char *)malloc(size + 1 * sizeof(char));
	size = 0;
	while (lst)
	{
		ret[size] = *(lst->content);
		lst = lst->next;
		size++;
	}
	ret[size] = '\0';
	return (ret);
}

char	*ft_strrchr(const char *str, int c)
{
	char	*tcstr;
	char	tcc;
	int		i;

	tcstr = (char *)str;
	tcc = (char)c;
	i = ft_strlen(tcstr);
	while (i && *(tcstr + i) != tcc)
		--i;
	if (*(tcstr + i) == tcc)
		return (tcstr + i);
	return (0);
}

int	ft_countdigits(int n)
{
	int		i;
	long	nr;

	i = 0;
	nr = n;
	if (nr == 0)
		return (1);
	if (nr < 0)
	{
		nr = nr * -1;
		i++;
	}
	while (nr > 0)
	{
		nr = nr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		len;

	nbr = n;
	len = ft_countdigits(nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	len--;
	while (nbr >= 10)
	{
		str[len] = (nbr % 10) + 48;
		nbr = nbr / 10;
		len--;
	}
	str[len] = nbr + 48;
	return (str);
}

void	ft_exitvalue(t_list **lst)
{
	char	*int_result;
	t_list	*temp;
	int		size;
	t_list	*zeroth;

	temp = 0;
	int_result = ft_itoa(g_main.exitval);
	argtolst(int_result, &temp);
	lst_detach(lst);
	zeroth = temp;
	*((*lst)->content) = *(temp->content);
	size = ft_lstsize(temp);
	temp = temp->next;
	while (--size > 0)
	{
		lst_append(lst, *(temp->content));
		temp = temp->next;
		*lst = (*lst)->next;
	}
	free_lst(&zeroth);
	free(int_result);
}
