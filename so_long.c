/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:38:20 by cgama             #+#    #+#             */
/*   Updated: 2024/09/16 13:38:22 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_info	game;

	init_struct(&game);
	if (argc != 2)
		map_error();
	game.argc_tmp = argc;
	game.argv_tmp = argv;
	if (is_file_map(argv[1], &game))
	{
		init_game(&game);
		set_hooks(&game);
		mlx_loop(game.mlx_ptr);
	}
	else
		map_error();
	close_game(&game);
	return (0);
}

void	init_struct(t_game_info *game)
{
	t_objects	*objects;

	*game = (t_game_info){0};
	game->map_init.matrice = NULL;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->resolutions_init.settings_name_map = NULL;
	game->resolutions_init.settings_name_window = NULL;
	objects = malloc(sizeof(t_objects));
	if (objects == NULL)
		map_error();
	game->objects = *objects;
	free (objects);
	return ;
}
