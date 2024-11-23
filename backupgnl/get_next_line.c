#include "get_next_line.h"
#include <string.h>

static void	ft_join(char const *s1, char const *s2, char **r)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		(*r)[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		(*r)[i + j] = s2[j];
		j++;
	}
	(*r)[i + j] = '\0';
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	r = (char *)malloc(sizeof(char) * (1 + i + j));
	if (!r)
		return (NULL);
	ft_join(s1, s2, &r);
	free(s1);
	return (r);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*r;
	unsigned int	smax;

	i = 0;
	smax = 0;
	while (s[smax])
		smax++;
	while (smax >= start && (s + start)[i] && i < len)
		i++;
	r = (char *)malloc(sizeof(char) * (i + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (smax >= start && (s + start)[i] && i < len)
	{
		r[i] = (s + start)[i];
		i++;
	}
	r[i] = '\0';
	free(s);
	return (r);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}
void	cleanbuff(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!ft_strchr(s, '\n'))
	{
		bzero(s, BUFFER_SIZE);
		return;
	}
	//1. arrive au nl
	while ((s)[i] != '\n' && i < BUFFER_SIZE)
		i++;
	//2. esquive le nl
	if ((s)[i] == '\n' && i <= BUFFER_SIZE)
			i++;
	//3. copie au debut
	while ((s)[i] && i < BUFFER_SIZE)
	{
		(s)[j] = (s)[i];
		i++;
		j++;
	}
	//4. met des zeros sur le reste
	while (j < BUFFER_SIZE)
	{
		(s)[j] = 0;
		j++;
	}
}
#include<stdio.h>
char	*get_next_line(int fd)
{
	static char	s[BUFFER_SIZE + 2] = {0};
	char		*r;
	int			readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, s, 0) == -1)
		return (NULL);
	readbytes = 1;	
	r = calloc(1, 1);
	while (readbytes || s[0] != 0)
	{
		r = ft_strjoin(r, s);
		if (ft_strchr(r, '\n') || (s[0] && !ft_strchr(r, '\n')))
		{
			cleanbuff(s);
			//printf("chaine restante:%s\n", s);
			r = ft_substr(r, 0, ft_strchr(r, '\n') - r + 1);
			return (r);
		}
		readbytes = read(fd, s, BUFFER_SIZE);
		/*if (readbytes == 0 && s[0])
		{
			free(r);
			r = strdup(s);
			return (r);
		}*/
		//memset(s, 0, BUFFER_SIZE);
	}
	//printf("chaine restante:%s\n", s);
	/*if (!ft_strchr(r, '\n') && r[0])
		return (r);*/
	free(r);
	return(NULL);	
}
/*get static */
