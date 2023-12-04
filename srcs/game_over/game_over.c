/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:49:12 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:25 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	game_over_sucess(t_root *root)
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
