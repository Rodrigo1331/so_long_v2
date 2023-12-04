/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_counters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:10:04 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:21:54 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_counters(t_root *root)
{
	root->counters.count_collect = 0;
	root->counters.count_collect_animation = 0;
	root->counters.count_move = 0;
	root->counters.count_patrol_animation = 0;
	root->counters.count_wall_animation = 0;
}
