/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:36:23 by cgama             #+#    #+#             */
/*   Updated: 2024/09/21 10:04:36 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hooks(t_game_info *game)
{
	mlx_hook(game->win_ptr, 17, 0, close_game, game);
	mlx_hook(game->win_ptr, 2, 1, ft_check_keyboard, game);
	mlx_loop_hook(game->mlx_ptr, &build_map, game);
}

int	ft_print_shell(t_game_info *game)
{
	static int	previous_count_movements = -1;
	int			current_count_movements;

	current_count_movements = game->counter.count_movements;
	if (current_count_movements != previous_count_movements)
	{
		ft_printf("movement: %d.\n", current_count_movements);
		previous_count_movements = current_count_movements;
	}
	return (1);
}

int	ft_events_pressed(t_game_info *g, int column, int row)
{
	int	r;
	int	c;
	int	current_tile;

	ft_locate_player(g);
	r = g->positions_init.player_row + row;
	c = g->positions_init.player_col + column;
	current_tile = g->map_init.matrice[r][c];
	if (current_tile == EMPTY || current_tile == COLLECTIBLE)
	{
		g->map_init.matrice[r][c] = PLAYER;
		g->map_init.matrice[g->positions_init.player_row]
		[g->positions_init.player_col] = EMPTY;
		g->positions_init.player_row = r;
		g->positions_init.player_col = c;
		if (current_tile == COLLECTIBLE)
			g->counter.count_collectible--;
		g->counter.count_movements++;
	}
	else if (current_tile == EXIT
		&& g->counter.count_collectible == 0)
	{
		you_win(g);
	}
	return (ft_print_shell(g));
}

void	ft_locate_player(t_game_info *game)
{
	int	col;
	int	row;

	row = 0;
	while (game->map_init.matrice[row] != NULL)
	{
		col = 0;
		while (game->map_init.matrice[row][col] != '\0')
		{
			if (game->map_init.matrice[row][col] == PLAYER)
			{
				game->positions_init.player_row = row;
				game->positions_init.player_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}
