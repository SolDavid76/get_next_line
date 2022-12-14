/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:05:10 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/12 15:31:11 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		tmp[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	int			x;
	int			i;

	x = 1;
	if (!stash)
		stash = "";
	while (x)
	{
		if (read(fd, tmp, BUFFER_SIZE) == 0)
			x = 0;
		tmp[BUFFER_SIZE] = '\0';
		stash = ft_strjoin(stash, tmp);
		i = 0;
		while (stash[i])
		{
			if (stash[i++] == '\n')
				x = 0;
		}
	}
	line = ft_substr(stash, 0, ft_backn(stash));
	stash = ft_substr(stash, ft_backn(stash) + 1, ft_strlen(stash));
	return (line);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	write(1, "\n", 1);
}
#include <fcntl.h>
int	main(void)
{
	int	fd;
	char *res;

	fd = open("test.txt", O_RDONLY);
	res = get_next_line(fd);
	ft_putstr(res);
	res = get_next_line(fd);
	ft_putstr(res);
	//res = get_next_line(fd);
	//ft_putstr(res);
	free(res);
}
