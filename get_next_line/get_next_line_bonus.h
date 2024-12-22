/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:53:35 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/22 15:54:05 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE 
#define BUFFER_SIZE 42
#endif

#include <stdio.h>
#include <libc.h>

char    *get_next_line(int fd);
char    *ft_strdup(char *s1);
char    *ft_strjoin(char *s1, char  *s2);
char    *find_new_line(char *s);
int     ft_strlen(char *sttr);
void    ft_strcat(char *dest, char *src);

#endif