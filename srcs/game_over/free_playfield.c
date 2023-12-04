/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_playfield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:09:30 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:20 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	playfield_free(t_root *root)
{
	size_t	lines;

	lines = 0;
	if (!root->playfield.playfield)
		return (0);
	while (lines < root->playfield.lin)
	{
		free(root->playfield.playfield[lines]);
		lines++;
	}
	free(root->playfield.playfield);
	lines = 0;
	if (!root->playfield.playfield_mask)
		return (0);
	while (lines < root->playfield.lin)
	{
		free(root->playfield.playfield_mask[lines]);
		lines++;
	}
	free(root->playfield.playfield_mask);
	return (1);
}
