/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:29:36 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/21 09:51:39 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *ft_(char *sst)
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
    if (!line)
        return (NULL);
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
    // free(sst);
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
    bombo = malloc(j - i); /// j - i + 1
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
    return (bombo);
}
char *ft_read(char *x, int fd)
{
    int a;
    char *buffer;
    char *temp;

    a = 1;
    buffer = malloc((size_t)BUFFER_SIZE + 1);
    if (!buffer)
        return (free(x), NULL);
    while (a != 0)
    {
        a = read(fd, buffer, BUFFER_SIZE);
        if (a == -1)
            return (free(x), free(buffer), NULL);
        buffer[a] = '\0';
        temp = ft_strjoin(x,buffer);
        free(x);
        x = temp;
        if(ft_find_back(buffer))
            break;
    }
    free(buffer);
    return (x);
}
char *get_next_line(int fd)
{
    char *line;
    static char *x[OPEN_MAX];
    int a;

    a = 1;
    if(fd < 0 || BUFFER_SIZE > 2147483647 || read(fd, 0, 0) < 0)
        return (NULL);
    if (!x[fd])
        x[fd] = ft_strdup("");
    x[fd] = ft_read(x[fd],fd);
    if(!*x[fd])
        return (free(x[fd]), NULL);
    line = ft_putstr(x[fd]);
    if (!line)
        return (free(x[fd]), NULL);
    x[fd] = reset(x[fd]);
    if (!x[fd])
        return (free(line), NULL);
    return (line);
}

// int main()
// {
//     int fd = open("bra.txt", O_CREAT | O_RDWR);
//     int fds = open("ben.txt", O_CREAT | O_RDWR);
//     // int fd = 3;
//     // char *linec;
//     printf("%d.%d\n",fd,fds);
//     // size_t i = ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean nisi tellus, laoreet nec tortor in, iaculis luctus erat. Nullam quis lacus vitae risus volutpat finibus. Donec vitae elit quis nisi consequat sagittis nec ac dolor. Nunc vehicula rutrum lectus, et dignissim quam hendrerit non. Nam congue malesuada diam, vestibulum sagittis orci malesuada ut. Donec imperdiet diam erat, sit amet dapibus dolor convallis volutpat. Mauris a sagittis felis, nec accumsan lorem. Nulla eu orci venenatis odio venenatis lacinia. Nullam nec turpis ut diam pharetra pellentesque. Maecenas dapibus dui ac turpis dictum mollis. Vivamus turpis nibh, scelerisque eu consectetur sed, congue eu enim. Proin consequat neque a arcu pulvinar ornare maximus sit amet nibh.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean nisi tellus, laoreet nec tortor in, iaculis luctus erat. Nullam quis lacus vitae risus volutpat finibus. Donec vitae elit quis nisi consequat sagittis nec ac dolor. Nunc vehicula rutrum lectus, et dignissim quam hendrerit non. Nam congue malesuada diam, vestibulum sagittis orci malesuada ut. Donec imperdiet diam erat, sit amet dapibus dolor convallis volutpat. Mauris a sagittis felis, nec accumsan lorem. Nulla eu orci venenatis odio venenatis lacinia. Nullam nec turpis ut diam pharetra pellentesque. Maecenas dapibus dui ac turpis dictum mollis. Vivamus turpis nibh, scelerisque eu consectetur sed, congue eu enim. Proin consequat neque a arcu pulvinar ornare maximus sit amet nibh.Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean nisi tellus, laoreet nec tortor in, iaculis luctus erat. Nullam quis lacus vitae risus volutpat finibus. Donec vitae elit quis nisi consequat sagittis nec ac dolor. Nunc vehicula rutrum lectus, et dignissim quam hendrerit non. Nam congue malesuada diam, vestibulum sagittis orci malesuada ut. Donec imperdiet diam erat, sit amet dapibus dolor convallis volutpat. Mauris a sagittis felis, nec accumsan lorem. Nulla eu orci venenatis odio venenatis lacinia. Nullam nec turpis ut diam pharetra pellentesque. Maecenas dapibus dui ac turpis dictum mollis. Vivamus turpis nibh, scelerisque eu consectetur sed, congue eu enim. Proin consequat neque a arcu pulvinar ornare maximus sit amet nibh.");

//     printf("%s",get_next_line_bonus(fd));
//     printf("%s",get_next_line_bonus(fds));
    
    
//     // while ((line = get_next_line(fd)))
//     // {
//     //     printf("line : %s", line);
//     //     free(line);
//     // }
//     // printf("%s",line);
//     // if (line == NULL)
//     //     printf("(null)");
//     // printf("%zd",i);
// }