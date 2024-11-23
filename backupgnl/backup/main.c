#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*int main(void)
{
	int		fd;
	char	*s;

	fd = open("File.txt", O_RDONLY);
	if (fd == -1)
		return(1);
	printf("%d\n",BUFFER_SIZE);
	s = get_next_line(fd);
	printf("String n*1: |%s|\n\n\n", s);
	free(s);
	s = get_next_line(fd);
	printf("String n*2: |%s|\n\n\n", s);
	free(s);
	close(fd);
	return 0;
}*/

int	main()
{
	int		fd;
	char	*line;

	fd = open("File.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("\nResultats :%s\n", line);
		free(line);
	}
	/*line = get_next_line(fd);
	printf("\nResultats :%s\n", line);
	free(line);*/
	close(fd);
	return (0);
}

/*int	main(void)
{
	char	s;
	int	fd = open("File.txt", O_RDONLY);
	read(fd, &s, 0);
}*/
