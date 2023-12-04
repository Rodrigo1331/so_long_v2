/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:18:29 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:27:14 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	hero_animation(t_root *root)
{
	if (root->hero.direction == UP)
		root->hero.path = root->path.hero_up;
	else if (root->hero.direction == DOWN)
		root->hero.path = root->path.hero_down;
	else if (root->hero.direction == LEFT)
		root->hero.path = root->path.hero_left;
	else if (root->hero.direction == RIGHT)
		root->hero.path = root->path.hero_right;
}
