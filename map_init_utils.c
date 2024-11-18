/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:37:39 by cgama             #+#    #+#             */
/*   Updated: 2024/09/16 13:42:11 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_dimensions(t_game_info *game)
{
	game->map_init.cols_matrice = get_cols_count(&game->map_init);
	if (game->map_init.cols_matrice == 0)
		return (0);
	return (get_rows_count(game));
}

int	get_cols_count(t_map_data *map_init)
{
	char	*row;
	int		cols_count;

	row = map_init->matrice[0];
	cols_count = 0;
	while (*row && *row != '\n')
	{
		cols_count++;
		row++;
	}
	return (cols_count);
}

int	get_rows_count(t_game_info *game)
{
	int	row_index;
	int	row_len;

	row_index = 0;
	while (game->map_init.matrice[row_index])
	{
		row_len = ft_strlen(game->map_init.matrice[row_index])
			- (game->map_init.matrice[row_index]
			[ft_strlen(game->map_init.matrice[row_index]) - 1] == '\n');
		if (row_len != game->map_init.cols_matrice)
		{
			game->map_init.rows_matrice = 0;
			return (0);
		}
		game->map_init.rows_matrice++;
		row_index++;
	}
	game->map_init.size_matrice = game->map_init.rows_matrice
		* game->map_init.cols_matrice;
	game->map_init.resolutions.settings_map_width
		= game->map_init.cols_matrice;
	game->map_init.resolutions.settings_map_height
		= game->map_init.rows_matrice;
	return (1);
}

int	ft_map_extension(char *map)
{
	char		*extension;
	char		*file_extension;
	static int	file_count;

	file_count = 0;
	extension = ".ber";
	file_extension = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		map_error();
		return (0);
	}
	else if (!file_extension || !ft_strcmp(file_extension, ""))
		return (0);
	else if (file_extension && !ft_strcmp(file_extension, extension))
	{
		if (file_count >= MAX_FILES)
			return (0);
		file_count++;
	}
	else
		return (0);
	return (1);
}
