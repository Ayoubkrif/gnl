
#include "get_next_line.h"
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char		*line;
	int			readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) = -1)
		return (NULL);
	readed = 1;
	line = NULL;
	//1 . add what we read of fd in stash
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	//2. extrat from stash to line
	
	//2. clean up stash
	return (line);
}

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return;
	while (!found_newline(*stash) && *readed_ptr)
	{
		*readed_ptr = read(fd, buff, BUFFER_SIZE);
		if ((*stash) == NULL && (*readed_ptr >= 0))

		buff[*readed_ptr] = '\0';
	}
}
void	add_to_stash()
{

}
void	extract_line()
{

}

int	found_newline(t_list *stash)
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
}
