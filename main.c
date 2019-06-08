#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int	main(int argc, char const *argv[])
{
	int fd;
	//int fd_2;
	char *line;
	int status;

	fd = open(argv[1], O_RDONLY);
	// fd_2 = open(argv[2], O_RDONLY);
	// status = 1;
	// while (status)
	// {
	// 	status = get_next_line(fd, &line);
	// 	printf("[%d] %s\n", fd, line);
	// 	free(line);
	// 	status = get_next_line(fd_2, &line);
	// 	printf("[%d] %s\n", fd_2, line);
	// 	free(line);
	// }

	status = get_next_line(fd, &line);
	printf("[%d] %s\n", fd, line);
		free(line);
	// status = get_next_line(fd, &line);
	// printf("[%d] %s\n", fd, line);
	// 	free(line);
	return (argc);
}