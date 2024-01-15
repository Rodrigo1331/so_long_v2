/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:06:19 by rcruz-an          #+#    #+#             */
/*   Updated: 2024/01/15 12:19:52 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*rewrite_stash(char *s)
{
	char	*new_s;
	int		i;
	int		j;

	i = line_length_gnl(s);
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	j = 0;
	new_s = ft_calloc((ft_strlen(s) - i + 1), sizeof(char));
	i++;
	while (s[i])
		new_s[j++] = s[i++];
	if (s[i] == '\0')
	{
		free(new_s);
		new_s = 0;
	}
	free (s);
	return (new_s);
}

char	*end_line(char *s)
{
	char	*l;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	l = ft_calloc((line_length_gnl(s) + 2), sizeof(char));
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		l[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		l[i] = '\n';
	return (l);
}

char	*last_line(char *s, int fd)
{
	char	*t;
	int		i;

	if (!s)
		s = ft_calloc(1, 1);
	t = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	i = 1;
	while (is_it_the_last_line_gnl(s) == 0 && i != 0)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i == -1)
		{
			free (t);
			free (s);
			return (NULL);
		}
		t [i] = '\0';
		s = ft_strjoin_gnl(s, t);
	}
	free (t);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s = last_line(s, fd);
	if (!s)
		return (NULL);
	l = end_line(s);
	s = rewrite_stash(s);
	return (l);
}
