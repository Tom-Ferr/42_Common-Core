#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void f(int fd, char *buf) {
	int size;
	size = read(fd+1, buf, 6);
	//printf("%s\n", buf );
	printf("%d\n", size);
	read(fd, &buf[2], 2);
	//printf("%s\n", buf );
}

int  main() {
	char buf[10];
	int fd;
	int fd2;
	fd = open("test.txt", O_RDONLY);
	f(fd, buf);
	f(fd, buf);
	return 0;
}
