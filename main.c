#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int ac, char **av) 
{ 
	char	*line;
	int		fd;

	ac = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}
