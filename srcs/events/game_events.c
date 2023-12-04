/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:09:03 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:35 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_door_open(t_root *root)
{
	if (root->counters.count_collect <= 0)
	{
		root->flags.is_door_open = 1;
		root->playfield.playfield[root->exit.y][root->exit.x] = 'O';
	}
}

void	game_events(t_root *root)
{
	check_door_open(root);
}
