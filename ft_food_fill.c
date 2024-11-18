/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_food_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:16:28 by cgama             #+#    #+#             */
/*   Updated: 2024/09/19 16:13:26 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_copies(char *filename)
{
	char	*line;
	int		lines;
	int		fd_map;
	char	**clone_map;

	lines = ft_count_lines(open(filename, O_RDONLY));
	clone_map = malloc(sizeof(char *) * (lines + 1));
	fd_map = open(filename, O_RDONLY);
	line = get_next_line(fd_map);
	lines = 0;
	while (line != NULL && line[0] != '\0')
	{
		clone_map[lines] = ft_strdup(line);
		lines++;
		free(line);
		line = get_next_line(fd_map);
	}
	clone_map[lines] = NULL;
	free(line);
	close(fd_map);
	return (clone_map);
}

void	flood_fill(t_map_data *data, char **clone_map, int x, int y)
{
	if (x < 0 || y < 0 || y > data->rows_matrice || x > data->cols_matrice)
		return ;
	if (clone_map[y][x] == 'E')
		clone_map[y][x] = '1';
	if (clone_map[y][x] == 'C' || \
			clone_map[y][x] == 'E' || clone_map[y][x] == '0'
		|| clone_map[y][x] == 'P')
	{
		clone_map[y][x] = '.';
		flood_fill(data, clone_map, x + 1, y);
		flood_fill(data, clone_map, x - 1, y);
		flood_fill(data, clone_map, x, y + 1);
		flood_fill(data, clone_map, x, y - 1);
	}
}

static void	find_player(char **matrix, t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == 'P')
			{
				data->positions.player_row = i;
				data->positions.player_col = j;
			}
			j++;
		}
		i++;
	}
	data->rows_matrice = i;
	data->cols_matrice = j;
}

int	flood_fill_validate(char **clone_map, t_map_data *data)
{
	int	x;

	find_player(clone_map, data);
	x = 0;
	flood_fill(data, clone_map,
		data->positions.player_col, data->positions.player_row);
	while (clone_map[x] != NULL)
	{
		if (ft_strchr(clone_map[x], 'E') != NULL || \
			ft_strchr(clone_map[x], 'C') != NULL)
		{
			free_matrix(clone_map);
			return (0);
		}
		x++;
	}
	free_matrix(clone_map);
	return (1);
}
