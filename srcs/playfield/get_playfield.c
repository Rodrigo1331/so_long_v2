/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_playfield.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 20:38:15 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:22:26 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_map_size(t_root *root)
{
	char	*temp;

	root->playfield.lin = 0;
	temp = get_next_line(root->map_file.fd);
	while (temp)
	{
		root->playfield.col = ft_strlen(temp);
		root->playfield.lin++;
		free(temp);
		temp = get_next_line(root->map_file.fd);
	}
	free(temp);
	close(root->map_file.fd);
	return (1);
}

void	get_playfield(t_root *root)
{
	size_t	lines;

	lines = 0;
	get_map_size(root);
	if (root->playfield.lin > 0)
	{
		root->playfield.playfield = malloc(sizeof(char *) * \
		root->playfield.lin);
		root->playfield.playfield_mask = malloc(sizeof(char *) \
			* root->playfield.lin);
		root->map_file.fd = open(root->map_file.path, O_RDONLY);
		while (lines < root->playfield.lin)
		{
			root->playfield.playfield[lines] = get_next_line(root->map_file.fd);
			root->playfield.playfield_mask[lines] = \
				ft_strdup(root->playfield.playfield[lines]);
			if (!root->playfield.playfield[lines])
				break ;
			lines++;
		}
	}
	else
		root->flags.has_init_error = 1;
	close(root->map_file.fd);
}
