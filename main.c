#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*s;

	fd = open("File.txt", O_RDONLY);
	if (fd == -1)
		return(1);
	printf("%d\n",BUFFER_SIZE);
	s = get_next_line(fd);
	//printf("1: |%s|\n", s);
	free(s);
	s = get_next_line(fd);
	//printf("2: |%s|\n", s);
	free(s);
	close(fd);
	return 0;
}
