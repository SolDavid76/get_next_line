/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:05:10 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/12 14:02:02 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*read_buff(int fd, char *res)
{
	read(fd, res, BUFFER_SIZE);
	res[BUFFER_SIZE] = '\0';
	return (res);
}*/

/*char	*read_line(int fd, char *res)
{
	char	*tmp;
	int		i;
	
	tmp = read_buff(fd);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (i != ft_strlen(tmp))
		return (ft_strjoin(res, tmp));
	return (read_line(fd, ft_strjoin(res, tmp)));
}*/

char	*get_next_line(int fd)
{
	char	*stach;
	char	*res;
	int		x;
	int		i;

	x = 1;
	res = "";
	while (x)
	{
		read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE + 1] = '\0';
		i = 0;
		while(tmp[i])
		{
			if (tmp[i] == '\n')
				x = 0;
			i++;
		}
		res = ft_strjoin(res, tmp);
	}
	return (res);
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
}
