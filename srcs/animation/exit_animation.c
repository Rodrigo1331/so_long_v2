/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:21:06 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:27:11 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	exit_animation(t_root *root)
{
	if (root->flags.is_door_open)
		root->exit.path = root->path.opened_door;
}
