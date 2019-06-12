#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int	main(int argc, char const *argv[])
{
	int fd;
	int fd2;
	int fd3;
	char *line;
	int status;

	argc = 1;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);
	//fd3 = open(argv[3], O_RDONLY);
	status = 1;
	while (status)
	{
		status = get_next_line(fd, &line);
		//printf("%s || return = %d\n", line, status);
		//printf("%s\n", line);
		free(line);
	//	status = get_next_line(fd2, &line);
	//	printf("|%s| %d\n", line, status);
	//	free(line);
	}
	// status = get_next_line(fd, &line);
	// printf("[%d] %s\n", fd, line);
	// 	free(line);
	// status = get_next_line(fd2, &line);
	// printf("[%d] %s\n", fd2, line);
	// 	free(line);
	// 	status = get_next_line(fd, &line);
	// printf("[%d] %s\n", fd, line);
	// 	free(line);
	// status = get_next_line(fd2, &line);
	// printf("[%d] %s\n", fd2, line);
	// 	free(line);
	
	// status = get_next_line(fd3, &line);
	// printf("[%d] %s\n", fd3, line);
	// //free(line);
	// ft_strdel(&line);
	// printf("\nstatus = %d\n", status);

	// status = get_next_line(fd3, &line);
	// printf("[%d] %s\n", fd3, line);
	// if (line)
	// 	free(line);
	// printf("\nstatus = %d\n", status);
	// return (argc);
}