/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djanusz <djanusz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:02:03 by djanusz           #+#    #+#             */
/*   Updated: 2022/12/12 15:09:47 by djanusz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

char    *get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_backn(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, unsigned int start, size_t len);

#endif
