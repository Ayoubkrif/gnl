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

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

#include<stdio.h>
char	*get_next_line(int fd)
{
	static char	*s;
	char *r;
	char	*temp;
	int		n;

	
	printf("la string restante est |%s|\n", s);
	r = calloc(sizeof(char), 1);
	if (!s)
		s = calloc(sizeof(char), BUFFER_SIZE + 1);
	else if (strchr(s, '\n'))
	{
		r = ft_substr(s ,strchr(s, '\n') - s + 1, 1000);
	}
	printf("la string restante est  devenue |%s|\n", r);
	while (read(fd, s, BUFFER_SIZE) > 0)
	{
		s[BUFFER_SIZE] = 0;
		r = ft_strjoin(r, s);
		if (strchr(r, '\n'))
		{
			
			r = ft_substr(r, 0, strchr(r, '\n') - r + 1);
			printf("la string retournee est |%s|\n\n", r);
			return (r);
		}
	}
	return(NULL);	
}
/*get static */
