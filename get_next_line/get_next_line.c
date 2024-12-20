/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:20:47 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/20 16:46:50 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_putstr(char *sst)
{
    int s;
    int i;
    int x;
    char *line;

    s = 0;
    i = 0;
    x = 1;
    while(sst[s] && sst[s] != '\n')
        s++;
    if(sst[s] == '\n')
        x = 2;
    line = malloc(s + x);
    while (sst[i] && sst[i] != '\n')
    {
        line[i] = sst[i];
        i++;
    }
    if (sst[i] == '\n')
    { 
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return(line);
}

char *reset(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    char *bombo;
    if (!*str)
        return (free(str), NULL);
    while(str[i] && str[i] != '\n')
        i++;
    j = ft_strlen(str);
    bombo = malloc(j - i + 1);
    if (!bombo)
        return NULL;
    int a = 0;
    i++;
    while(str[i])
    {
        bombo[a] = str[i];
        i++;
        a++;
    }
    bombo[a] = '\0';
    free(str);
    return bombo;
}
char *ft_read(char *x, int fd)
{
    int a;
    char *buffer;

    a = 1;
    buffer = malloc((size_t)BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;
    while (a != 0)
    {
        a = read(fd, buffer, BUFFER_SIZE);
        if (a == -1)
            return (free(buffer), NULL);
        buffer[a] = '\0';
        x = ft_strjoin(x,buffer);
        if(ft_find_back(buffer))
            break;
    }
    free(buffer);
    return (x);
}
char *get_next_line(int fd)
{
    char *line_bonus;
    static char *x;
    int a;

    a = 1;
    if(BUFFER_SIZE > 2147483647 || fd < 0)
        return (NULL);
    if (!x)
        x = ft_strdup("");
    x = ft_read(x,fd);
    if(!*x)
        return (NULL);
    line_bonus = ft_putstr(x);
    x = reset(x);
    return (line_bonus);
}

void v(void)
{
    system("leaks a.out");
}
int main()
{
    atexit(v);
    // system("a.out");
    int fd = open("bra.txt", O_CREAT | O_RDWR);
    // int fds = open("ben.txt", O_CREAT | O_RDWR);
    // int fd = 3;
    // char *line;
    // printf("%d.%d\n",fd,fds);
    printf("%s",get_next_line(fd));
    // close(fd);
    // printf("%s",get_next_line(fds));
    
    
    // while ((line = get_next_line(fd)))
    // {
    //     printf("line : %s", line);
    //     free(line);
    // }
    // printf("%s",line);
    // if (line == NULL)
    //     printf("(null)");
    // printf("%zd",i);
}