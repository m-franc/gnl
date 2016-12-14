#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDWR);

	while (get_next_line(fd, &line))
		printf("\033[31mligne : %s\n\033[0m", line);
}
