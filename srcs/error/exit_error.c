/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:08:26 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:45 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	exit_game_init_error(t_root *root)
{
	playfield_free(root);
	free(root->path.collect);
	exit (EXIT_FAILURE);
	return (0);
}

int	exit_ingame_error_(t_root *root)
{
	mlx_clear_window(root->mlx.mlx, root->mlx.win);
	mlx_destroy_window(root->mlx.mlx, root->mlx.win);
	mlx_destroy_display(root->mlx.mlx);
	free(root->mlx.mlx);
	free(root->path.collect);
	ft_printf("Error\nSome important files are missing!\n");
	ft_printf("Sorry for the inconvenience!\n");
	exit (EXIT_FAILURE);
	return (0);
}
