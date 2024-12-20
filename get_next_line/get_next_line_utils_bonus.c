/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbenaali <bbenaali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:50:27 by bbenaali          #+#    #+#             */
/*   Updated: 2024/12/20 16:02:52 by bbenaali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *sttr)
{
    int i;

	i = 0;
    while (sttr[i] != '\0')
        i++;
    return (i);
}
void	ft_strcat(char *dest, char *src)
{
    int i;

    i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
char	*ft_strdup(char *s1)
{
	int		i;
	int	len;
	char	*copy;

	len = ft_strlen(s1);
	i = 0;
	copy = malloc (sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}


char	*ft_strjoin(char *s1, char  *s2)
{
	int	len;
	int	i;
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (s3 == NULL)
		return (NULL);
	ft_strcat(s3, s1);
	i = ft_strlen(s3);
	ft_strcat(&s3[i], s2);
	return (s3);
}