#include "get_next_line.h"

static char *stock;
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

int checkN(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (i);
}
// we used this function so we can free the old stock without worries :D
// this function gives ft_substr a copy of stock so we can free stock
// without worrying about having memory leaks and then use it to make
// stock store what has been left and line store "string ended with newline"
char *splitit(char *line, char *stac)
{
    int i;

    i = 0;
    while(stock[i] != '\n')
    {
        i++;
    }
    line = ft_substr(stac, 0, i+1);
    // if ()//todo : if its null then bla bla bla else free the stock
    if (stac[i+1] != '\0')
        stock = ft_substr(stac, i+1, ft_strlen(stac) - i);
    else
    {
        free(stock);
        stock = NULL;
    }
    return (line);
}

char    *get_next_line(int fd)
{
    char *strh = NULL;
    char *line = NULL;

    if (fd < 0 || fd == 1 || fd == 2)
        return (NULL);
    strh = (char *)malloc(BUFFER_SIZE + 1);
    if (stock == NULL)
        stock = (char *)malloc(BUFFER_SIZE + 1);
    while(checkN(stock) != 1)
    {
        read(fd, strh, BUFFER_SIZE);
        stock = ft_strjoin(stock, strh);
    }
    free(strh);

    // printf("%c\n", stock[0]);
    printf("stock: %s    ---\n", stock);
    line = splitit(line, stock);
    printf("stock: %s    ---\n", stock);
    return (line);
}

int main()
{
    int fd;
    fd = open("btata.txt", O_CREAT | O_RDONLY);
    printf("%s",  get_next_line(fd));
}
