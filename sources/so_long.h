/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:12:05 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/05/17 11:05:57 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_struct
{
	int				fd;
	int				player_x;
	int				player_y;
	int				count_player;
	int				count_exit;
	int				count_collectible;
	int				count_move;
	int				screen_width;
	int				screen_height;
	int				map_width;
	int				map_height;
	int				map_tile_width;
	int				map_tile_height;
	char			**map;
	mlx_image_t		*player_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*collectible_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*exit_img;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_t			*mlx_ptr;
}	t_struct;

int		check_borders(t_struct *game_struct);
int		check_counts(t_struct *game_struct);
int		check_collectibles(t_struct *game_struct);
int		check_extension(char *map_path);
void	check_escape(t_struct *game_struct);
int		check_exit(t_struct *game_struct);
void	check_items(t_struct *game_struct);
int		check_player_spawn(t_struct *game_struct);
int		check_count_collectibles(t_struct *game_struct);
void	check_map(t_struct *game_struct);
int		check_map_shape(t_struct *game_struct);
void	exit_game(t_struct *game_struct);
void	exit_game_error(t_struct *game_struct, int num);
void	exit_map_error(t_struct *game_struct, int num);
void	exit_more_map_error(t_struct *game_struct, int num);
void	flood_fill(int y, int x, t_struct *game_struct);
void	flood_fill_check(t_struct *game_struct, int y, int x);
void	ft_movement_y(t_struct *game_struct, char direction);
void	ft_movement_x(t_struct *game_struct, char direction);
void	game_init(t_struct *game_struct);
void	load_all_textures(t_struct *game_struct);
void	map_load(t_struct *game_struct, char *map_path);
void	map_free(char **map);
int		map_valid(t_struct *game_struct);
int		map_width(char *line);
int		new_window(t_struct *game_struct);
char	**player_current_position(t_struct *game_struct);
void	player_spawn_position(t_struct *game_struct);
void	textures_load(t_struct *game_struct);

//hooks
void	hooks(t_struct *game_struct);
void	ft_keyboard(mlx_key_data_t keydata, void *ptr);

//get next line
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_move_start(char *start);
char	*ft_strjoin(char *s1, char *s2);

//printf
int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printdigit(long n, int base, int uppercase);
int		ft_printptr(unsigned long long ptr);
int		ft_printstr(char *str);

#endif