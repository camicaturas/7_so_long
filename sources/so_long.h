/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:12:05 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/04/15 17:10:55 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_struct
{
	int				fd;
	int				playercount;
	int				exitcount;
	int				collectiblecount;
	int				y;
	int				x;
	int				height;
	int				width;
	int				movecount;
	char			**map;
	mlx_texture_t	*floor;
	mlx_image_t		*floor_img;
	mlx_texture_t	*wall;
	mlx_image_t		*wall_img;
	mlx_texture_t	*character;
	mlx_image_t		*character_img;
	mlx_texture_t	*collectible;
	mlx_image_t		*collectible_img;
	mlx_texture_t	*horse;
	mlx_image_t		*horse_img;
	mlx_t			*mlx_ptr;
}	t_struct;

void	map_load(char *map_path, t_struct *game);
void	map_check(t_struct *game);
int		map_parse(t_struct *game);

void	exit_succes(t_struct *game);
void	exit_error(t_struct *game, int num);

void	game_init(t_struct *game);

void	load_all_textures(t_struct *game);
void	get_player_position(t_struct *game);

#endif


