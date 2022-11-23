/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:53:29 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/22 18:46:49 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*strh;
	char		*line;
	int			i;
	int			j;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	strh = ft_calloc(1, BUFFER_SIZE + 1);
	if (!strh)
		return (NULL);
	if (stock == NULL)
	{
		stock = ft_calloc(1, BUFFER_SIZE + 1);
		if (!stock)
			return (NULL);
	}
	j = 1;
	while (checkn(stock) != 1 && j != 0)
	{
		j = read(fd, strh, BUFFER_SIZE);
		if (j == -1)
		{
			free(stock);
			stock = NULL;
			free(strh);
			strh = NULL;
			return (NULL);
		}
		else if (j > 0)
			stock = ft_strjoin(stock, strh, j);
	}
	free(strh);
	strh = NULL;
	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	if (j == 0 && ft_strlen(stock) == 0)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	else if (stock != NULL && stock[i] == '\0')
	{
		line = stock;
		stock = NULL;
		return (line);
	}
	else
	{
		line = ft_substr(stock, 0, i + 1);
		stock = cut_stock(stock, i);
	}
	return (line);
}

int main()
{
    int fd;
    fd = open("btata.txt", O_CREAT | O_RDONLY);
    printf("%s", get_next_line(fd));
}