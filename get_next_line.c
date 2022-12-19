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
	char		*stash;
	int			n;

	n = 1;
	stash = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_strchr(tmp, '\n'))
		stash = ft_endcpy(tmp);
	while (!ft_strchr(stash, '\n') && n != 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
			return (free(stash), NULL);
		if (n == 0)
		{
			if (ft_strlen(stash) == 0)
				return (free(stash), NULL); //dumbest thing I'll never do
			return (stash);
		}
		tmp[n] = '\0';
		stash = ft_strjoin(stash, tmp);
		if (!stash)
			return (NULL);
	}
	return (ft_get_line(stash));
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

	fd = open("test.txt", O_RDONLY);
	i = 2;
	while (i)
	{
		res = get_next_line(fd);
		ft_putstr(res);
		free(res);
		i--;
	}
}
*/
