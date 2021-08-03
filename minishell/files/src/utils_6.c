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
