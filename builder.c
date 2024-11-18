/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:52:12 by cgama             #+#    #+#             */
/*   Updated: 2024/09/19 14:52:15 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	build_map(t_game_info *game)
{
	int	row;
	int	column;

	row = -1;
	while (game->map_init.matrice[++row])
	{
		column = 0;
		while (game->map_init.matrice[row][column])
		{
			if (game->map_init.matrice[row][column] == WALL)
				set_image(game, game->objects.wall, column, row);
			if (game->map_init.matrice[row][column] == EMPTY)
				set_image(game, game->objects.empty, column, row);
			if (game->map_init.matrice[row][column] == PLAYER)
				set_image(game, game->objects.player, column, row);
			change_exit(game, column, row);
			if (game->map_init.matrice[row][column] == COLLECTIBLE)
				set_image(game, game->objects.collectible,
					column, row);
			column++;
		}
	}
	return (0);
}

void	change_exit(t_game_info *game, int column, int row)
{
	if (game->map_init.matrice[row][column] == EXIT
		&& game->counter.count_collectible == 0)
		set_image(game, game->objects.exit_open, column, row);
	if (game->map_init.matrice[row][column] == EXIT
		&& game->counter.count_collectible != 0)
		set_image(game, game->objects.exit_close, column, row);
	return ;
}

void	set_image(t_game_info *game, void *img, int wid, int hgt)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, wid * CELL_SIZE, hgt * CELL_SIZE);
}
