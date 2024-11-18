/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:40 by cgama             #+#    #+#             */
/*   Updated: 2024/09/19 15:10:03 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_error(void)
{
	ft_printf("%sError with initialization");
	exit(1);
}

void	map_error(void)
{
	ft_printf("%sError with map.\n");
	exit(1);
}

void	ft_free_map(t_game_info *game)
{
	int	i;

	if (game->map_init.matrice == NULL)
		return ;
	i = 0;
	while (game->map_init.matrice[i])
	{
		free(game->map_init.matrice[i]);
		i++;
	}
	free(game->map_init.matrice);
	game->map_init.matrice = NULL;
	return ;
}

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix == NULL)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
	return ;
}

void	ft_free_img(t_game_info *game)
{
	mlx_destroy_image(game->mlx_ptr, game->objects.player_up);
	mlx_destroy_image(game->mlx_ptr, game->objects.player_left);
	mlx_destroy_image(game->mlx_ptr, game->objects.player_right);
	mlx_destroy_image(game->mlx_ptr, game->objects.player_down);
	mlx_destroy_image(game->mlx_ptr, game->objects.collectible);
	mlx_destroy_image(game->mlx_ptr, game->objects.exit_open);
	mlx_destroy_image(game->mlx_ptr, game->objects.exit_close);
	mlx_destroy_image(game->mlx_ptr, game->objects.wall);
	mlx_destroy_image(game->mlx_ptr, game->objects.empty);
	game->objects = (t_objects){0};
}
