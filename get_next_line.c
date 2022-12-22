/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:27:33 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/22 12:31:19 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readstash(int fd, char *str)
{
	int		n;
	char	*tmp;

	n = 1;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(str, '\n') && n != 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
			return (free(tmp), NULL);
		if (n == 0)
			return (free(tmp), str);
		tmp[n] = '\0';
		str = ft_strjoin(str, tmp);
	}
	return (free(tmp), str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_readstash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_clean(stash);
	if (!line)
		return (free(stash), NULL);
	return (line);
}
/*
#include <fcntl.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)\n", 7);
		return (0);
	}
	while (str[i])
		i+= write(1, str + i, 1);
	return (i);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*res;

	fd = open("test", O_RDONLY);
	i = 1;
	while (i)
	{
		res = get_next_line(fd);
		i = ft_putstr(res);
		free(res);
	}
}
*/
