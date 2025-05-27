/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:21:22 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/05/17 11:15:03 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_texture(t_struct *game_struct)
{
	game_struct->player = mlx_load_png("./assets/textures/player.png");
	game_struct->player_img = mlx_texture_to_image(game_struct->mlx_ptr,
			game_struct->player);
	game_struct->wall = mlx_load_png("./assets/textures/wall.png");
	game_struct->wall_img = mlx_texture_to_image(game_struct->mlx_ptr,
			game_struct->wall);
	game_struct->collectible = mlx_load_png(
			"./assets/textures/collectible.png");
	game_struct->collectible_img = mlx_texture_to_image(
			game_struct->mlx_ptr, game_struct->collectible);
	game_struct->floor = mlx_load_png("./assets/textures/floor.png");
	game_struct->floor_img = mlx_texture_to_image(game_struct
			->mlx_ptr, game_struct->floor);
	game_struct->exit = mlx_load_png("./assets/textures/exit.png");
	game_struct->exit_img = mlx_texture_to_image(
			game_struct->mlx_ptr, game_struct->exit);
	if (!game_struct->player || !game_struct->wall || !game_struct->collectible
		|| !game_struct->floor || !game_struct->exit)
		exit_game_error(game_struct, 4);
}

static void	render_texture(t_struct *game_struct, int y, int x)
{
	if (game_struct->map[y][x] == '1')
		if (mlx_image_to_window(game_struct->mlx_ptr, game_struct->wall_img,
				x * game_struct->map_tile_width, y
				* game_struct->map_tile_height) < 0)
			exit_game_error(game_struct, 4);
	if (game_struct->map[y][x] == '2' || game_struct->map[y][x] == 'c'
			|| game_struct->map[y][x] == 'p'
			|| game_struct->map[y][x] == 'e')
		if (mlx_image_to_window(game_struct->mlx_ptr, game_struct->floor_img,
				x * game_struct->map_tile_width, y
				* game_struct->map_tile_height) < 0)
			exit_game_error(game_struct, 4);
	if (game_struct->map[y][x] == 'c')
		if (mlx_image_to_window(game_struct->mlx_ptr,
				game_struct->collectible_img,
				x * game_struct->map_tile_width, y
				* game_struct->map_tile_height) < 0)
			exit_game_error(game_struct, 4);
	if (game_struct->map[y][x] == 'e')
		if (mlx_image_to_window(game_struct->mlx_ptr, game_struct->exit_img,
				x * game_struct->map_tile_width, y
				* game_struct->map_tile_height) < 0)
			exit_game_error(game_struct, 4);
}

void	textures_load(t_struct *game_struct)
{
	int	y;
	int	x;

	y = 0;
	init_texture(game_struct);
	while (game_struct->map[y])
	{
		x = 0;
		while (game_struct->map[y][x])
		{
			render_texture(game_struct, y, x);
			x++;
		}
		y++;
	}
	game_struct->player_img = mlx_texture_to_image(game_struct->mlx_ptr,
			game_struct->player);
	if (mlx_image_to_window(game_struct->mlx_ptr, game_struct->player_img,
			game_struct->player_x * game_struct->map_tile_width,
			game_struct->player_y * game_struct->map_tile_height) < 0)
		exit_game_error(game_struct, 4);
	if (!game_struct->player_img || !game_struct->wall_img
		|| !game_struct->collectible_img
		|| !game_struct->floor_img || !game_struct->exit_img)
		exit_game_error(game_struct, 4);
}
