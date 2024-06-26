/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 00:07:43 by rcruz-an          #+#    #+#             */
/*   Updated: 2023/12/04 16:22:35 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input(int keycode, t_root *root)
{
	if (keycode == ESC)
		exit_game_request(root);
	else if (keycode == UP || keycode == DOWN || \
			keycode == LEFT || keycode == RIGHT)
		check_move_sprite(root, keycode);
	return (0);
}

void	setup_game(t_root *root)
{
	root->collect = malloc(sizeof(t_sprite) * root->quant.quant_collect);
	render_map(root);
}

int	main(int argc, char const *argv[])
{
	t_root	root;

	if (argc != 2)
	{
		ft_printf("Enter map file: eg. ./solong map.ber !\n");
		return (1);
	}
	root.map_file.path = (char *)argv[1];
	init_game(&root);
	if (root.flags.has_init_error)
		print_error(&root);
	root.mlx.mlx = mlx_init();
	root.mlx.win = mlx_new_window(root.mlx.mlx, \
		(root.playfield.col) * BITS, (root.playfield.lin + 1) \
		* BITS, "so long");
	setup_game(&root);
	mlx_key_hook(root.mlx.win, input, &root);
	mlx_loop_hook(root.mlx.mlx, game_loop, &root);
	mlx_hook(root.mlx.win, 17, 0, exit_game_request, &root);
	mlx_loop(root.mlx.mlx);
	exit(EXIT_SUCCESS);
	return (1);
}
