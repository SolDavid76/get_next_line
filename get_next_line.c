/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:27:33 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/19 10:45:02 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	tmp[BUFFER_SIZE + 1];
	char		*line;
	int			n;

	n = 1;
	line = NULL;
	if (ft_strchr(tmp, '\n'))
		line = ft_endcpy(tmp);
	while (!ft_strchr(line, '\n') && n != 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
			return (free(line), NULL);
		if (n == 0)
			return (line);
		tmp[n] = '\0';
		line = ft_strjoin(line, tmp);
		if (!line)
			return (NULL);
	}
	line = ft_get_line(line);
	return (line);
}
/*
#include <fcntl.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i+= write(1, str + i, 1);
	return (i);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	i = 1;
	while (i)
	{
		res = get_next_line(fd);
		i = ft_putstr(res);
		free(res);
	}
}
*/
