#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdarg.h>

static char		*make_str(int n, ...)
{
	va_list my_chars;
	char *str;
	int i;

	va_start(my_chars, n);
	i = 0;
	str = (char *)malloc(n + 1);
	while(n > i)
	{
		str[i] = va_arg(my_chars, int);
		i++;
	}
	str[n] = '\0';
	va_end(my_chars);
	return (str);
}

static void		free_params(char const *s1, char const *s2)
{
	free((void*)s1);
	free((void*)s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*ptr;

	i = 0;
	j = 0;
	size = (strlen(s1) + strlen(s2)) + 1;
	ptr = (char*)malloc(size);
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	ptr[i] = '\0';
	free_params(s1, s2);
	return (ptr);
}

int main(int argc, char const *argv[]) {
	char *n = make_str(2, '4', '2');
	//char *m = make_str(2, '!', '@');
	char *j = ft_strjoin(n, make_str(2, '!', '@'));
	printf("%s\n", j);
	return 0;
}
