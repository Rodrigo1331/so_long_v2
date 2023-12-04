/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:07:56 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:27:04 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	collision(t_sprite *element1, t_sprite *element2)
{
	if (element1->x == element2->x && element1->y == element2->y)
		return (1);
	return (0);
}
