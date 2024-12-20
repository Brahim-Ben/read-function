/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 08:20:26 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/20 15:06:56 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <libc.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
 
char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char  *s2);
void	ft_strcat(char *dest, char *src);
char	*ft_strdup(char *s1);
char	*ft_find_back(char const *s);
int ft_strlen(char *sttr);

#endif