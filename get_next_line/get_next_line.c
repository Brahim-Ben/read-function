/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 07:57:43 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/22 16:01:41 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_before(char *str)
{
    int i;
    char *bombo;
    int x;
    
    x = 1;
    i = 0;
    while(str[i] && str[i] != '\n')
        i++;
    // i = find_new_line(str);
    // j = ft_strlen(str);
    if(str[i] == '\n')
        x = 2;
    bombo = malloc(i + x);
    if(!bombo)
        return (free(str), free(bombo), NULL);
    i = 0;
    // printf("%d\n",i);
    while(str[i] && str[i] != '\n')
    {
       bombo[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        bombo[i] = '\n';
        i++;
    }
    bombo[i] = '\0';
    // free(str);
    return (bombo);
}

char *after(char *sttr)
{
    int i;
    int j;
    char *s;

    i = 0;
    while(sttr[i] && sttr[i] != '\n')
        i++;
    j = ft_strlen(sttr);
    // printf("%d\n",i);
    s = malloc(j - i + 1);
    if(!s)
        return (free(s), free(sttr), NULL);
    if(sttr[i] == '\n')
        i++;
    j = 0;
    while(sttr[i] != '\0')
    {
        s[j] = sttr[i];
        j++;
        i++;
    }
    s[j] = '\0';
    // printf("%s\n", s);
    free(sttr);
    // sttr = NULL;
    // printf("%s\n",sttr);
    return (s);
}

char *ft_read(int fd, char *x)
{
    int a;
    char *buffer;
    char *temp;
    
    a = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    while (a)
    {
        a = read(fd, buffer, BUFFER_SIZE);
        if (a < 0)
        {
            free(buffer);
            return (free(x), NULL);
        }
        buffer[a] = '\0';
        temp = x;
        x = ft_strjoin(temp, buffer);
        free(temp);
        // if (!temp)
        //     return (free(temp),free(x), NULL);
        // x = temp;
        if( !x || a == 0 ||  find_new_line(buffer))
            break;
    } 
    // if(!*x)
    //     return (free(x), free(buffer), NULL);
    free(buffer);
    return (x);
}




char *get_next_line(int fd)
{
    static char *x;
    // int a;
    // char *buffer;
    // char *temp;
    char *line;
    // char *sk;

    // a = 1;
    if(fd < 0 ||  read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
        return (free(x), x = NULL, NULL);
    // if(x == NULL)
    //     x = ft_strdup("");
    x = ft_read(fd, x);
    // buffer = malloc(BUFFER_SIZE + 1);
    // if (!buffer)
    //     return (NULL);
    // while (a != 0)
    // {
    //     a = read(fd, buffer, BUFFER_SIZE);
    //     if (a < 0)
    //         return (free(x), free(buffer), NULL);
    //     buffer[a] = '\0';
    //    temp = x;
    //     x = ft_strjoin(temp, buffer);
    //     free(temp);
    //     // temp = NULL;
    //     // if (!temp)
    //     //     return (free(temp), NULL);
    //     // temp = x;
    //     // x = temp;
    //     // temp = NULL;
    //     if(find_new_line(buffer))
    //         break;
    // } 
    if(!x || !*x)
        return (free(x), x = NULL, NULL);
    // free(buffer);
    line = ft_before(x);
    if(!line)
        return (x = NULL);
    x = after(x);
    // if(!x)
    //     return (free(x), NULL);
    return (line);
}







// char *read_and_append(int fd, char *x)
// {
//     char    *buffer;
//     char    *temp;
//     int     bytes_read;

//     buffer = malloc(BUFFER_SIZE + 1);
//     if (!buffer)
//         return (NULL);
//     while (1)
//     {
//         bytes_read = read(fd, buffer, BUFFER_SIZE);
//         if (bytes_read < 0)
//         {
//             free(buffer);
//             return (free(x), NULL);
//         }
//         buffer[bytes_read] = '\0';
//         temp = x;
//         x = ft_strjoin(temp, buffer);
//         free(temp);
//         if (!x || bytes_read == 0 || find_new_line(buffer))
//             break;
//     }
//     free(buffer);
//     return (x);
// }

// char *get_next_line(int fd)
// {
//     static char *x;
//     char        *line;

//     if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
//         return (free(x), x = NULL, NULL);
//     x = read_and_append(fd, x);
//     if (!x || !*x)
//         return (free(x), x = NULL, NULL);
//     line = ft_before(x);
//     if (!line)
//         return (free(x), x = NULL);
//     x = after(x);
//     return (line);
// }





// void v()
// {
//     system("leaks a.out");
// }
// int main ()
// {
//     atexit(v);
//     int fd = open("text.txt", O_CREAT | O_RDWR, 0777);
//     char *line;
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     // printf("%s", get_next_line(fd));
//     while((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     // if (line == NULL)
//     //     printf("NULL");
// }


        // tmp = x;
        // x = ft_strjoin(tmp, buffer);
        // free(tmp);
        // tmp = NULL;