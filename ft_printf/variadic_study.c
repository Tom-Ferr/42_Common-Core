#include <stdarg.h>
#include <stdio.h>

int function(va_list args)
{
	return (va_arg(args, int));
}
void sum(int n, ...)
{
	va_list args;
	va_start(args, n);
	int i = function(args);
	while (--n)
		i += function(args);
	va_end(args);
	printf("%i\n", i);
}

int main() {
	sum(5, 1, 2, 3, 4, 5);
	return 0;
}
