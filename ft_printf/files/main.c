
int		ft_printf(const char *format, ...);
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
int main(void) {
	int ft;
	int fp;
	ft = ft_printf("%-054.78d\n", 42);
	fp = printf("%-054.78d\n", 42);
	printf("%d\n%d\n", ft, fp);
	return 0;
}
