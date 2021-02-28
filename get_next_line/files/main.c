#include "get_next_line.h"
#include "stdio.h"
#include "fcntl.h"

int main() {
	int fd = open("big_line_no_nl", O_RDONLY);
	char	*line;
	while (get_next_line(fd, &line) > 0)
		printf("%s\n",	line );
	printf("%s\n",	line );
	free(line);
	return 0;
}
