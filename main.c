#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av) 
{ 
	char	*line;
	int		fd;

	line = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_next_line(fd, &line);
		printf("%s\n", line);
	}
	return (0);
}
