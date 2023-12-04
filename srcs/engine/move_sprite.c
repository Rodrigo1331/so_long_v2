/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:08:04 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:27:01 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(t_root *root, t_sprite *element, t_sprite *behind)
{
	root->playfield.playfield[element->y][element->x] = behind->control;
	put_sprite(root, behind, element->y, element->x);
	element->y--;
	element->direction = UP;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_down(t_root *root, t_sprite *element, t_sprite *behind)
{
	root->playfield.playfield[element->y][element->x] = behind->control;
	put_sprite(root, behind, element->y, element->x);
	element->y++;
	element->direction = DOWN;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_right(t_root *root, t_sprite *element, t_sprite *behind)
{
	root->playfield.playfield[element->y][element->x] = behind->control;
	put_sprite(root, behind, element->y, element->x);
	element->x++;
	element->direction = RIGHT;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_left(t_root *root, t_sprite *element, t_sprite *behind)
{
	root->playfield.playfield[element->y][element->x] = behind->control;
	put_sprite(root, behind, element->y, element->x);
	element->x--;
	element->direction = LEFT;
	root->playfield.playfield[element->y][element->x] = element->control;
}

void	move_sprite(t_root *root, t_sprite *element, t_sprite *behind, \
		int direction)
{
	if (direction == UP)
		move_up(root, element, behind);
	if (direction == DOWN)
		move_down(root, element, behind);
	if (direction == RIGHT)
		move_right(root, element, behind);
	if (direction == LEFT)
		move_left(root, element, behind);
}
