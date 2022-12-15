/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:05:10 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/15 15:00:50 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readstash(int fd, char *str)
{
	char	*tmp;
	int		n;

	tmp = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	n = 1;
	while (!ft_strchr(str, '\n') && n != 0)
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[n] == '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
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
	return (line);
}

/*char	*ft_free_return(char **stash)
{
	char	*tmp;
	char	*line;

	tmp = *stash;
	line = ft_substr(tmp, 0, ft_backn(tmp));
	*stash = ft_substr(tmp, ft_backn(tmp) + 1, ft_strlen(tmp));
	return (line);
}

char	*get_next_line(int fd)
{
	char		tmp[BUFFER_SIZE + 1];
	static char	*stash;
	int			x;
	int			i;

	x = 1;
	if (!stash)
		stash = "";
	while (x)
	{
		if (read(fd, tmp, BUFFER_SIZE) < 1)
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
	return (ft_free_return(&stash));
}*/

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
	free(res);
	res = get_next_line(fd);
	ft_putstr(res);
	free(res);
}
