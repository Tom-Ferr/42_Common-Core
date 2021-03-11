
int		ft_printf(const char *format, ...);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
int main(void) {
	int ft;
	int fp;
	int *p = malloc(1*4);
	ft = ft_printf("%06.2%\n");
	fp = printf("%06.2%\n");
	printf("%d\n%d\n", ft, fp);
	return 0;
}
