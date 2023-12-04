/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:40:28 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/01/09 12:18:14 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/* void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;
	int		n;

	i = 0;
	n = nmemb * size;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	while (n-- > 0)
		ptr[i++] = '\0';
	return (ptr);
} */

int	is_it_the_last_line_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

/* size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
} */

size_t	line_length_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	i = 0;
	j = 0;
	while (ft_strlen(s1) > i)
	{
		str[i] = s1[i];
		i++;
	}
	free (s1);
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
