#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char				*ft_strjoin(char *s1, char *s2, int size);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif