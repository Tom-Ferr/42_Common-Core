#include <stdlib.h>
#include <stdio.h>
#include <string.h>


size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*tdest;
	size_t	dlen;
	char	*tcsrc;

	tcsrc = (char*)src;
	dlen = ft_strlen(dest);
	tdest = dest + dlen;
	if (size <= dlen)
		return (ft_strlen(src) + size);
	while (*tcsrc && (--size) - dlen)
		*(tdest++) = *(tcsrc++);
	*tdest = '\0';
	return (ft_strlen(src) + dlen);
}

int	main()
	{
		char dest[300] ={"YRWrba3"};
		char src[200] = {"qrZ9cw R9r8YSKAVPnXN e4ApOfCwKx6u8 QgiIlZEuFyR 4hZg5fiLaQNu OAPglvR NXa580lfmzZcRKGy TDFk qp0bX iY8tn4FUxP1gc phVfDS rHN7omveGVM m7KtTbaQNE"};
		printf("%zu\n", ft_strlcat(dest, src, 2));
		printf("%s\n", dest);
	}
