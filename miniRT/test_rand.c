#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ft_rand(void)
{
	static int first;
	static unsigned long int next;
	if (!first++)
		next = (unsigned long int)&next;
    next = next * 1103515243 + 12345;
    return (unsigned int)(next / 65536) % INT_MAX;
}

double random_double(void)
{
    return rand() / (RAND_MAX + 1.0);
}

// void ft_srand(unsigned int seed)
// {
//     next = seed;
// }


int main() {
	for (size_t i = 0; i < 100; i++) {
		printf("%f\n", random_double());
	}


	return 0;
}
