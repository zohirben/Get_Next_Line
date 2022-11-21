/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbenaiss <zbenaiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:53:29 by zbenaiss          #+#    #+#             */
/*   Updated: 2022/11/21 12:30:17 by zbenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int checkN(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
	{
		str[i++] = '\0';
	}
	return (str);
}

char *cut_stock(char *save, int i)
{
    char    *cache;

    if (!save)
        return NULL;
    if (save[i+1] == '\0')
    {
        free(save);
        return (NULL);
    }
    cache = ft_substr(save, i+1, ft_strlen(save));
    free(save);
    save = 0;
    return (cache);
}

char *get_next_line(int fd)
{
    static char *stock;
    char *strh;
    char *line;
    int i;
    int j;

    if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
        return (NULL);
    strh = calloc(1 ,BUFFER_SIZE + 1);
    if (!strh)
        return (NULL);
    strh[BUFFER_SIZE] = '\0';
    if (stock == NULL)
    {
        stock = calloc(1, BUFFER_SIZE + 1);
        if (!stock)
            return (NULL);
        stock[BUFFER_SIZE] = '\0';
    }
    j = 1;
    while (checkN(stock) != 1 && j != 0)
    {
        j = read(fd, strh, BUFFER_SIZE);
        if(j == -1)
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
        line = ft_substr(stock, 0, i+1);
        stock = cut_stock(stock, i);
    }
    return (line);
}

// int main()
// {
//     int fd;
//     fd = open("btata.txt", O_CREAT | O_RDONLY);
//     printf("%s", get_next_line(fd));
// }