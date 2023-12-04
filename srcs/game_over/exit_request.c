/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_request.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:09:20 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:17 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_game_request(t_root *root)
{
	mlx_clear_window(root->mlx.mlx, root->mlx.win);
	mlx_destroy_window(root->mlx.mlx, root->mlx.win);
	mlx_destroy_display(root->mlx.mlx);
	free(root->mlx.mlx);
	free(root->path.collect);
	playfield_free(root);
	free(root->collect);
	ft_printf("Thanks for playing!!\nHave a great day!\n");
	exit (EXIT_SUCCESS);
	return (0);
}
