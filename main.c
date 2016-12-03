#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		fd;
	char	**line;

	if (ac == 1)
		return (0);
	fd = open(av[1], O_RDWR);
	if (!(line = (char**)malloc(sizeof(char*) * 1000)))
		return (0);
	while (get_next_line(fd, line) == 1)
		printf("%d\n", get_next_line(fd, line));
	free(line);
}
