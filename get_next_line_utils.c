/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:01:58 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/12 16:05:25 by djanusz          ###   ########.fr       */
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

int	ft_backn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
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
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	while ((int)(start + i) < ft_strlen(str) && i < len)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while ((int)i < ft_strlen(str) && j < len)
	{
		res[j++] = str[i++];
	}
	res[j] = 0;
	return (res);
}
