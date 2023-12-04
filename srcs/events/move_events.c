/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:09:09 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:39 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_move_wall(t_root *root, int direction)
{
	if (direction == UP)
	{
		if (root->playfield.playfield[root->hero.y - 1][root->hero.x] == '1')
			return (0);
	}
	if (direction == DOWN)
	{
		if (root->playfield.playfield[root->hero.y + 1][root->hero.x] == '1')
			return (0);
	}
	if (direction == RIGHT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x + 1] == '1')
			return (0);
	}
	if (direction == LEFT)
	{
		if (root->playfield.playfield[root->hero.y][root->hero.x - 1] == '1')
			return (0);
	}
	return (1);
}

void	check_move_sprite(t_root *root, int direction)
{
	if (check_move_wall(root, direction))
	{
		root->counters.count_move++;
		ft_printf("Moves %d\n", root->counters.count_move);
		move_sprite(root, &root->hero, &root->floor, direction);
	}
}
