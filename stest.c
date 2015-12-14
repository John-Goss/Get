#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av) 
{ 
	char *line; 
	int fd;

	(void)ac;
	(void)av;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		printf("%s\n", line);
	return (0);
}
