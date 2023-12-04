/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:55:56 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:22:22 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	call_flood_fill(t_root *root, int y, int x)
{
	if (root->playfield.playfield_mask[y][x] != '1')
	{
		root->playfield.playfield_mask[y][x] = '1';
		call_flood_fill(root, y, x + 1);
		call_flood_fill(root, y, x - 1);
		call_flood_fill(root, y + 1, x);
		call_flood_fill(root, y - 1, x);
	}
}

void	check_flood_fill(t_root *root)
{
	size_t	lin;
	size_t	col;

	lin = 0;
	col = 0;
	while (lin < root->playfield.lin)
	{
		while (col < root->playfield.col)
		{
			if (root->playfield.playfield_mask[lin][col] == 'C' || \
				root->playfield.playfield_mask[lin][col] == 'E')
			{
				root->flags.is_not_way_out = 1;
				root->flags.has_init_error = 1;
			}
			col++;
		}
		col = 0;
		lin++;
	}
}

void	flood_fill(t_root *root)
{
	int	x;
	int	y;

	x = root->hero.x;
	y = root->hero.y;
	call_flood_fill(root, y, x);
	check_flood_fill(root);
}
