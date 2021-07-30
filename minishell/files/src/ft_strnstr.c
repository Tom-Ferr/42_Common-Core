#include "minishell.h"

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = ft_strlen(needle);
	if (l == 0 || !needle)
		return ((char *)haystack);
	l--;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && j <= l && (i + j) < len)
		{
			if (j == l)
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
