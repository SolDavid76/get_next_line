/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:00:55 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/08 13:04:46 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*res;
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc(BUFFER_SIZE);
	read(fd, tmp, BUFFER_SIZE);
	res = malloc(sizeof(char) * (ft_strlen(tmp) + ft_strlen(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		res[j++] = tmp[i++];
	free(tmp);
	free(str);
	return (res);
}

char    *get_next_line(int fd)
{
	char	*res;
	int		i;

	res = NULL;
	res = read_line(fd, res);
	i = 0;
	while (res[i])
	{
		if (res[i] == '\n')
			return (res);
	}
	return (res);
}


#include <fcntl.h>
void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	while (str[i])
		i += write(1, str + i, 1);
}

int	main(void)
{
	int	fd_test;

	fd_test = open("test.txt", O_RDONLY);
	ft_putstr(get_next_line(fd_test));
	return (0);
}
