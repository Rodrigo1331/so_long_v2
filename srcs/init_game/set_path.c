/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:57:38 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:21:49 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_elements_path(t_root *root)
{
	root->path.floor = "./textures/floor.xpm";
	root->path.hero_right = "./textures/hero/hero_right.xpm";
	root->path.hero_left = "./textures/hero/hero_left.xpm";
	root->path.hero_up = "./textures/hero/hero_up.xpm";
	root->path.hero_down = "./textures/hero/hero_down.xpm";
	root->path.border_wall_hu = "./textures/walls/hu.xpm";
	root->path.closed_door = "./textures/elements/door_closed.xpm";
	root->path.opened_door = "./textures/elements/door_opened.xpm";
}

void	set_collect_path(t_root *root)
{
	root->path.collect = malloc(sizeof(char *) * 1);
	root->path.collect[0] = "./textures/elements/collect0.xpm";
}

void	set_init_path(t_root *root)
{
	root->hero.path = root->path.hero_right;
	root->hero.control = 'P';
	root->wall.path = root->path.inner_wall;
	root->wall.control = '1';
	root->exit.path = root->path.closed_door;
	root->exit.control = 'E';
	root->floor.path = root->path.floor;
	root->floor.control = '0';
}

void	set_path(t_root *root)
{
	set_collect_path(root);
	set_elements_path(root);
	set_init_path(root);
}
