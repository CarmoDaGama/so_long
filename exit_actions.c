/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:35:42 by cgama             #+#    #+#             */
/*   Updated: 2024/09/16 13:35:45 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game_info *game)
{
	ft_printf("Closing program..\n");
	ft_free_img(game);
	ft_free_map(game);
	ft_cleanup(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

void	ft_reset_game(t_game_info *game)
{
	ft_printf("\nGame reset.\n");
	ft_free_img(game);
	ft_free_map(game);
	free(game->resolutions_init.settings_name_window);
	free(game->resolutions_init.settings_name_map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	main(game->argc_tmp, game->argv_tmp);
}

void	ft_cleanup(t_game_info *game)
{
	if (game->resolutions_init.settings_name_window != NULL)
	{
		free(game->resolutions_init.settings_name_window);
		game->resolutions_init.settings_name_window = NULL;
	}
	if (game->resolutions_init.settings_name_map != NULL)
	{
		free(game->resolutions_init.settings_name_map);
		game->resolutions_init.settings_name_map = NULL;
	}
}
