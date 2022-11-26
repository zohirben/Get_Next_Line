/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:09:31 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/26 12:33:22 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*nerd(char *cache, int fd, int *j);
char	*checkerror(char *cache, int fd, int *j);
char	*get_next_line(int fd);
char	*cut_stock(char *save, int i);
int		checkN(char *str);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif