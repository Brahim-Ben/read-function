/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:29:36 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/20 15:22:56 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_find_back(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\n')
		return ((char *)&s[i]);
	return (NULL);
}


char *ft_putstr(char *sst)
{
    int s;
    int i;
    int x;
    char *line;

    s = 0;
    i = 0;
    x = 0;
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

// int ft_strlen(char *sttr)
// {
//     int i = 0;
//     while (sttr[i] != '\0')
//         i++;
//     return (i);
// }
// void	ft_strcat(char *dest, char *src)
// {
//     int i;

//     i = 0;
// 	while (src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// }
// char	*ft_strdup(char *s1)
// {
// 	int		i;
// 	int	len;
// 	char	*copy;

// 	len = ft_strlen(s1);
// 	i = 0;
// 	copy = malloc (sizeof(char) * (len + 1));
// 	if (copy == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		copy[i] = s1[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }


// char	*ft_strjoin(char *s1, char  *s2)
// {
// 	int	len;
// 	int	i;
// 	char	*s3;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	else if (!s1)
// 		return (ft_strdup(s2));
// 	else if (!s2)
// 		return (ft_strdup(s1));
// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	s3 = malloc(sizeof(char) * (len + 1));
// 	if (s3 == NULL)
// 		return (NULL);
// 	ft_strcat(s3, s1);
// 	i = ft_strlen(s3);
// 	ft_strcat(&s3[i], s2);
// 	return (s3);
// }

char *reset(char *str)
{
    int i;
    int j;
    char *bombo;
    int a;

    i = 0;
    j = 0;
    a = 0;
    while(str[i] && str[i] != '\n')
        i++;
    j = ft_strlen(str);
    bombo = malloc(j - i + 1);
    if (!bombo)
        return NULL;
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
char *get_next_line_bonus(int fd)
{
    char *line;
    static char *x[OPEN_MAX];
    int a;

    a = 1;
    if(BUFFER_SIZE > 2147483647 || fd < 0)
        return (NULL);
    if (!x[fd])
        x[fd] = ft_strdup("");
    x[fd] = ft_read(x[fd],fd);
    if(!*x[fd])
        return (NULL);
   
    line = ft_putstr(x[fd]);
    x[fd] = reset(x[fd]);
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