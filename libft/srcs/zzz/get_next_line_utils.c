/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:29:56 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/08/03 11:27:15 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(char *s, int c)
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (&ptr[i]);
		else
			i++;
	}
	if (ptr[i] == c)
		return (&ptr[i]);
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dest;
	size_t	len;

	len = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	dest[len] = '\0';
	free(s1);
	return (dest);
}
