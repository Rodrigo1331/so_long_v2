/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:07:35 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:22:02 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_tile(t_root *root, char tile, size_t y, size_t x)
{
	if (tile == 'P')
		put_sprite(root, &root->hero, y, x);
	else if (tile == '1')
	{
		root->wall.y = y;
		root->wall.x = x;
		root->wall.path = root->path.border_wall_hu;
		put_sprite(root, &root->wall, y, x);
	}
	else if (tile == 'C')
	{
		root->collect[root->quant.quant_collect - 1].path = \
		root->path.collect[0];
		root->collect[root->quant.quant_collect - 1].control = 'C';
		put_sprite(root, &root->collect[root->quant.quant_collect - 1], y, x);
		root->quant.quant_collect--;
	}
	else if (tile == 'E' || tile == 'O')
		put_sprite(root, &root->exit, y, x);
	else if (tile == '0')
		put_sprite(root, &root->floor, y, x);
}

void	render_map(t_root *root)
{
	size_t	lines;
	size_t	cols;

	lines = 0;
	cols = 0;
	while (lines < root->playfield.lin)
	{
		while (cols < root->playfield.col)
		{
			render_tile(root, root->playfield.playfield[lines][cols], \
				lines, cols);
			cols++;
		}
		cols = 0;
		lines++;
	}
	root->quant.quant_collect = root->counters.count_collect;
}
