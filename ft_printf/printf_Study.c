#include <stdio.h>
int main() {
	char *x = "1234567890";
	int ret;
	ret = printf("%05.10d\n",-123);
	printf("%d\n", ret);
	return 0;
}
