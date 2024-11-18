/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:37:53 by cgama             #+#    #+#             */
/*   Updated: 2024/11/18 15:54:55 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_valid_map(t_game_info *game)
{
	if (!(ft_count_map_objects(game)))
		return (0);
	if (!(ft_is_map_shape_valid(game)))
		return (0);
	if (!(ft_is_wall(game)))
		return (0);
	if (!(flood_fill_validate(
				map_copies(game->argv_tmp[1]), &game->map_init)))
		return (0);
	return (1);
}

int	ft_is_map_shape_valid(t_game_info *game)
{
	if (game->map_init.cols_matrice <= 0
		|| game->map_init.rows_matrice <= 0)
		return (0);
	if (game->map_init.size_matrice == 0)
		return (0);
	if (game->map_init.size_matrice % game->map_init.rows_matrice == 0
		&& game->map_init.size_matrice / game->map_init.rows_matrice
		== game->map_init.cols_matrice)
		return (1);
	return (0);
}

int	ft_is_wall(t_game_info *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_init.rows_matrice)
	{
		j = 0;
		while (j < game->map_init.cols_matrice)
		{
			if (i == 0 || j == 0 || i == game->map_init.rows_matrice
				- 1 || j == game->map_init.cols_matrice - 1)
			{
				if (game->map_init.matrice[i][j] != WALL)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_count_map_objects(t_game_info *game)
{
	int	row;
	int	column;

	row = -1;
	while (game->map_init.matrice[++row])
	{
		column = 0;
		while (game->map_init.matrice[row][column])
		{
			if (game->map_init.matrice[row][column] == PLAYER)
				game->counter.count_player++;
			else if (game->map_init.matrice[row][column] == EXIT)
				game->counter.count_exit++;
			else if (game->map_init.matrice[row][column] == COLLECTIBLE)
				game->counter.count_collectible++;
			else if (game->map_init.matrice[row][column] == WALL)
				game->counter.count_wall++;
			else if (game->map_init.matrice[row][column] == EMPTY)
				game->counter.count_empty++;
			else if (game->map_init.matrice[row][column] != '\n')
				return (0);
			column++;
		}
	}
	return (ft_have_requires(game));
}

int	ft_have_requires(t_game_info *game)
{
	if (!(game->counter.count_player == 1
			&& game->counter.count_exit == 1
			&& game->counter.count_collectible >= 1))
		return (0);
	return (1);
}
