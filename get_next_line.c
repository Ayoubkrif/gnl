/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aykrifa <aykrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:35:20 by aykrifa           #+#    #+#             */
/*   Updated: 2024/11/23 11:40:37 by aykrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cleanbuff(char *s, char *r)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (ft_strchr(s,'\n'))
	{
		while (s[i] != '\n' && i < BUFFER_SIZE + 1)
			i++;
		if (s[i] == '\n')
			i++;
		while (s[i] && i < BUFFER_SIZE + 1)
		{
			s[j] = s[i];
			i++;
			j++;
		}
	}
	while (j < BUFFER_SIZE + 1)
		s[j++] = '\0';
	//printf("Buffer clean : |%s|\n", s);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	s[BUFFER_SIZE + 1] = {0};
	char		*r;
	int			readbytes;

	r = calloc(sizeof(char), 1);
	r = ft_strjoin(r, s);
	if (ft_strchr(r, '\n') /*&& printf("a")*/)
		return (cleanbuff(s, ft_substr(r, 0, ft_strchr(r, '\n') - r + 1)));
	readbytes = 1;
	while (readbytes > 0)
	{
		readbytes = read(fd, s, BUFFER_SIZE);
		if (readbytes < 0)
			break;
		r = ft_strjoin(r, s);
		if (ft_strchr(r, '\n') /*&& s[1] && r[1]*//*&& printf("b")*/)
			return (cleanbuff(s, ft_substr(r, 0, ft_strchr(r, '\n') - r + 1)));
	}
	if (!ft_strchr(r, '\n') && s[0] /*&& r[0]*/ /*&& printf("c")*/)
		return (cleanbuff(s, r));
	free(r);
	return (NULL);
}
