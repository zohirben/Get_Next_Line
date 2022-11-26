/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:49:16 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/26 12:31:04 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	checkn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*cut_stock(char *save, int i)
{
	char	*cache;

	if (!save)
		return (NULL);
	if (save[i + 1] == '\0')
	{
		free(save);
		return (NULL);
	}
	cache = ft_substr(save, i + 1, ft_strlen(save));
	free(save);
	save = 0;
	return (cache);
}

char	*nerd(char *cache, int fd, int *j)
{
	char	*strh;

	strh = ft_calloc(1, BUFFER_SIZE + 1);
	*j = 1;
	while (checkn(cache) != 1 && *j != 0)
	{
		*j = read(fd, strh, BUFFER_SIZE);
		if (*j == -1)
		{
			free(cache);
			cache = NULL;
			free(strh);
			strh = NULL;
			return (NULL);
		}
		else if (*j > 0)
			cache = ft_strjoin(cache, strh, *j);
	}
	free(strh);
	strh = NULL;
	return (cache);
}

char	*checkerror(char *cache, int fd, int *j)
{
	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	if (cache == NULL)
		cache = ft_calloc(1, BUFFER_SIZE + 1);
	cache = nerd(cache, fd, j);
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*stock[10];
	char		*line;
	int			i;
	int			j;

	line = NULL;
	stock[fd] = checkerror(stock[fd], fd, &j);
	if (stock[fd] == NULL)
		return (NULL);
	i = 0;
	while (stock[fd][i] != '\n' && stock[fd][i])
		i++;
	if (stock[fd] != NULL && stock[fd][i] == '\n')
	{
		line = ft_substr(stock[fd], 0, i + 1);
		stock[fd] = cut_stock(stock[fd], i);
		return (line);
	}
	else if (j == 0 && ft_strlen(stock[fd]) == 0)
		free(stock[fd]);
	else
		line = stock[fd];
	stock[fd] = NULL;
	return (line);
}

// int main()
// {
//     int fd;
// 	int fd1;
//     fd = open("kob.txt", O_RDONLY);
// 	fd1 = open("btata.txt", O_RDONLY);
//     printf("%s", get_next_line(fd));
//     printf("%s", get_next_line(fd1));
//     printf("%s", get_next_line(fd));
// }