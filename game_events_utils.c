/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:36:37 by cgama             #+#    #+#             */
/*   Updated: 2024/09/16 13:36:40 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_keyboard(int key, t_game_info *game)
{
	ft_non_special(key, game);
	if (key == W || key == UP)
	{
		game->objects.player = game->objects.player_up;
		ft_events_pressed(game, 0, -1);
	}
	else if (key == A || key == LEFT)
	{
		game->objects.player = game->objects.player_left;
		ft_events_pressed(game, -1, 0);
	}
	else if (key == S || key == DOWN)
	{
		game->objects.player = game->objects.player_down;
		ft_events_pressed(game, 0, +1);
	}
	else if (key == D || key == RIGHT)
	{
		game->objects.player = game->objects.player_right;
		ft_events_pressed(game, +1, 0);
	}
	return (0);
}

int	ft_non_special(int key, t_game_info *game)
{
	if (key == ESC)
	{
		ft_printf("\nOh, closed with ESC :c\n");
		close_game(game);
	}
	else if (key == RESTART)
		ft_reset_game(game);
	return (0);
}

void	you_win(t_game_info *game)
{
	game->counter.count_movements++;
	ft_print_shell(game);
	game->map_init.matrice[game->positions_init.player_row]
	[game->positions_init.player_col] = EMPTY;
	game->counter.count_movements++;
	ft_printf("\nGreat! You win the game.\n");
	close_game(game);
}
