/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgama <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:38:36 by cgama             #+#    #+#             */
/*   Updated: 2024/09/19 16:00:45 by cgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "libft/include/libft.h"

# include <fcntl.h> 
# include <string.h> 

# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# define WALL '1'
# define EMPTY '0'

# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363
# define RESTART 114

# define MAX_FILES 1

# define TRUE 1
# define FALSE 0

# define CELL_SIZE 32

typedef struct s_objects
{
	void	*player;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*player_up;
	void	*collectible;
	void	*exit_open;
	void	*exit_close;
	void	*wall;
	void	*empty;
	int		img_width;
	int		img_height;
}	t_objects;

typedef struct s_positions
{
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
}	t_positions;

typedef struct s_counter
{
	int	count_player;
	int	count_exit;
	int	count_collectible;
	int	count_wall;
	int	count_empty;
	int	count_movements;
	int	endgame;
}	t_counter;

typedef struct s_resolutions
{
	int		settings_map_width;
	int		settings_map_height;
	char	*settings_name_window;
	char	*settings_name_map;
}	t_resolutions;

typedef struct s_map_data
{
	int					first_read_matrice;
	int					cols_matrice;
	int					rows_matrice;
	int					size_matrice;
	char				**matrice;
	t_resolutions		resolutions;
	t_positions			positions;
}			t_map_data;

typedef struct s_game_info
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					argc_tmp;
	char				**argv_tmp;
	t_map_data			map_init;
	t_positions			positions_init;
	t_counter			counter;
	t_resolutions		resolutions_init;
	t_objects			objects;
}					t_game_info;

int			main(int argc, char **argv);

void		init_struct(t_game_info *game);

void		init_game(t_game_info *game);
int			ft_check_keyboard(int key, t_game_info *game);
int			ft_non_special(int key, t_game_info *game);
int			close_game(t_game_info *game);
void		ft_reset_game(t_game_info *game);
int			is_file_map(char *map, t_game_info *game);
int			ft_read_count_map(char *map);
int			ft_count_lines(int fd);
int			ft_map_dimensions(t_game_info *game);
int			get_rows_count(t_game_info *game);
int			get_cols_count(t_map_data *map_init);
int			ft_read_map(int fd, t_game_info *game);
int			ft_check_read(t_game_info *game);
int			ft_map_extension(char *map);
int			ft_is_valid_map(t_game_info *game);
int			ft_is_map_shape_valid(t_game_info *game);
int			ft_is_wall(t_game_info *game);
int			ft_count_map_objects(t_game_info *game);
int			ft_have_requires(t_game_info *game);
void		set_hooks(t_game_info *game);
int			ft_events_pressed(t_game_info *game, int column, int row);
void		you_win(t_game_info *game);
int			ft_print_shell(t_game_info *game);
void		ft_reset_game(t_game_info *game);
void		ft_locate_player(t_game_info *game);
void		ft_img_init(t_game_info *game);
void		ft_check_img(t_game_info *game, void **image, char *path);
int			build_map(t_game_info *game);
void		change_exit(t_game_info *game, int column, int row);
void		set_image(t_game_info *game, void *img, int wid, int hgt);
void		ft_free_map(t_game_info *game);
void		ft_free_img(t_game_info *game);
void		ft_cleanup(t_game_info *game);
void		init_error(void);
void		map_error(void);
void		flood_fill( t_map_data *data, char **clone_map, int x, int y);
int			flood_fill_validate(char **clone_map, t_map_data *data);
void		free_matrix(char **matrix);
char		**map_copies(char *filename);

#endif
