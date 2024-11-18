/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:37:14 by cgama             #+#    #+#             */
/*   Updated: 2024/11/18 15:56:49 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_file_map(char *map, t_game_info *game)
{
	int			fd;

	if (!ft_map_extension(map))
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	game->map_init.first_read_matrice = ft_read_count_map(map);
	if (!game->map_init.first_read_matrice
		|| game->map_init.first_read_matrice < 3)
	{
		close (fd);
		ft_free_map(game);
		return (0);
	}
	if (!ft_read_map(fd, game))
	{
		close (fd);
		ft_free_map(game);
		return (0);
	}
	close (fd);
	return (1);
}

int	ft_read_count_map(char *map)
{
	int	fd;
	int	count;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	count = ft_count_lines(fd);
	if (close(fd) == -1)
		return (0);
	return (count);
}

int	ft_count_lines(int fd)
{
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	n_read;
	int		i;

	count = 0;
	while (1)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read < 0)
			return (0);
		if (n_read == 0)
			break ;
		i = 0;
		while (i < n_read)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	count++;
	return (count);
}

int	ft_read_map(int fd, t_game_info *game)
{
	int		i;
	char	*buffer;

	game->map_init.matrice
		= ft_calloc(game->map_init.first_read_matrice + 1, sizeof(char *));
	if (!game->map_init.matrice)
	{
		ft_free_map(game);
		return (0);
	}
	i = 0;
	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer || !*buffer)
			break ;
		game->map_init.matrice[i] = buffer;
		i++;
	}
	if (!ft_check_read(game))
		return (0);
	return (1);
}

int	ft_check_read(t_game_info *game)
{
	if (game->map_init.matrice[0] == NULL
		|| !ft_map_dimensions(game) || !ft_is_valid_map(game))
	{
		ft_free_map(game);
		return (0);
	}
	return (1);
}
