#include "get_next_line.h"

int	main()
{
	char *str;

	while (get_next_line(0, &str) == 1)
	{
		ft_putendl(str);
		free(str);
	}
	return (0);
}
