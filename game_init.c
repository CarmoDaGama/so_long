/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:36:52 by cgama             #+#    #+#             */
/*   Updated: 2024/09/16 13:36:55 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game_info *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		init_error();
	game->counter.count_movements = 0;
	ft_img_init(game);
	game->objects.player = game->objects.player_right;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->map_init.resolutions.settings_map_width
			* CELL_SIZE, game->map_init.resolutions.settings_map_height
			* CELL_SIZE, "The Medieval Knight");
	if (game->win_ptr == NULL)
		init_error();
}

void	ft_img_init(t_game_info *game)
{
	ft_check_img(game, &game->objects.player_up,
		"textures/player.xpm");
	ft_check_img(game, &game->objects.player_down,
		"textures/player.xpm");
	ft_check_img(game, &game->objects.player_right,
		"textures/player.xpm");
	ft_check_img(game, &game->objects.player_left,
		"textures/player.xpm");
	ft_check_img(game, &game->objects.collectible,
		"textures/collectible.xpm");
	ft_check_img(game, &game->objects.empty,
		"textures/empty.xpm");
	ft_check_img(game, &game->objects.exit_open,
		"textures/exit_open.xpm");
	ft_check_img(game, &game->objects.exit_close,
		"textures/exit_close.xpm");
	ft_check_img(game, &game->objects.wall,
		"textures/wall.xpm");
}

void	ft_check_img(t_game_info *game, void **image, char *path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	if (*image == NULL)
	{	
		init_error();
		close_game(game);
	}
}
