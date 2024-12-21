/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:50:43 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/21 09:04:10 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#include <unistd.h>
#include <stdlib.h>
#include <libc.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char  *s2);
void    ft_strcat(char *dest, char *src);
char    *ft_strdup(char *s1);
char    *ft_find_back(char const *s);
int     ft_strlen(char *sttr);

#endif