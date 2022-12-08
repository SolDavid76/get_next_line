/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:05:10 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/08 15:44:25 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;	
	int		j;

	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	free(s2);
	return (res);
}

char	*read_buff(int fd)
{
	char	*res;

	res = malloc(BUFFER_SIZE + 1);
	if (!res)
		return (NULL);
	read(fd, res, BUFFER_SIZE);
	res[BUFFER_SIZE + 1] = '\0';
	return (res);
}

char	*read_line(int fd, char *res)
{
	char	*tmp;
	int		i;
	
	tmp = read_buff(fd);
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (i != BUFFER_SIZE)
		return (ft_strjoin(res, tmp));
	return (read_line(fd, ft_strjoin(res, tmp)));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}
#include <fcntl.h>
int	main(void)
{
	int	fd;
	char *res;

	fd = open("test.txt", O_RDONLY);
	res = read_line(fd, "");
	ft_putstr(res);
}
