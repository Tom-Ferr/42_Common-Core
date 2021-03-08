#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static	void	write_symbol(long z, bool a)
{
	char c;

	c = 'a';
	if (a)
		c = 'A';
	if (z >= 10)
		z = (z % 10) + c;
	else
		z = z + '0';
	write(1, &z, 1);
}

void	dtox(long d, bool a)
{
	long n;
	long m;

	n = d / 16;
	m = d % 16;
	if (n < 16)
	{
		write_symbol(n, a);
		write_symbol(m, a);
	}
	else
	{
		dtox(n, a);
		write_symbol(m, a);
	}
}

int				ft_printf(const char *format, ...)
{
	va_list args;
	int p;

	p = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		write(1, format, 1);
		else
		{
			if (*(format + 1) == 'p' || *(format + 1) == 'x'
			||	*(format + 1) == 'X')
			{
				if (*(format + 1) == 'p')
					write(1, "0x", 2);
				dtox(va_arg(args, long), *(format + 1) == 'X');
			}
			else if (*(format + 1) == '%')
				write(1, "%", 1);
			format++;
		}
		format++;
		p++;
	}
	va_end(args);
	return (p);
}

int main(int argc, char const *argv[]) {
	int *x = malloc(1*4);
	int y = 1000;
	ft_printf("this is a hex: %p\n", x);
	printf("this is a hex: %p %X\n", x, y);
	return 0;
}
