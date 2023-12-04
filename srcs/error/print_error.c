/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:40:46 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:48 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	print_error(t_root *root)
{
	if (root->flags.has_init_error)
	{
		if (root->flags.is_collect_present == 0)
			ft_printf("Error\n");
		else if (root->flags.is_exit_present != 1)
			ft_printf("Error\n");
		else if (root->flags.is_player_present != 1)
			ft_printf("Error\n");
		else if (root->flags.is_not_square)
			ft_printf("Error\n");
		else if (root->flags.is_not_border)
			ft_printf("Error\n");
		else if (root->flags.is_not_way_out)
			ft_printf("Error\n");
		else if (root->flags.is_invalid_element)
			ft_printf("Error\n");
		else if (root->flags.is_not_ber)
			ft_printf("Error\n");
		exit_game_init_error(root);
	}
	return (0);
}
