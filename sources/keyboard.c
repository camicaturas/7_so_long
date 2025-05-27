/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/05/14 10:57:55 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement_y(t_struct *game_struct, char direction)
{
	if (direction == 'u')
	{
		if (game_struct->map[game_struct->player_y - 1]
			[game_struct->player_x] == '1')
			return ;
		game_struct->player_img->instances[0].y
			-= game_struct->map_tile_height;
		game_struct->player_y -= 1;
		ft_printf("You have moved %i times!\n", game_struct->count_move++);
	}
	if (direction == 'd')
	{
		if (game_struct->map[game_struct->player_y + 1]
			[game_struct->player_x] == '1')
			return ;
		game_struct->player_img->instances[0].y += game_struct->map_tile_height;
		game_struct->player_y += 1;
		ft_printf("You have moved %i times!\n", game_struct->count_move++);
	}
}

void	ft_movement_x(t_struct *game_struct, char direction)
{
	if (direction == 'l')
	{
		if (game_struct->map[game_struct->player_y]
			[game_struct->player_x - 1] == '1')
			return ;
		game_struct->player_img->instances[0].x
			-= game_struct->map_tile_height;
		game_struct->player_x -= 1;
		ft_printf("You have moved %i times!\n", game_struct->count_move++);
	}
	if (direction == 'r')
	{
		if (game_struct->map[game_struct->player_y]
			[game_struct->player_x + 1] == '1')
			return ;
		game_struct->player_img->instances[0].x
			+= game_struct->map_tile_height;
		game_struct->player_x += 1;
		ft_printf("You have moved %i times!\n", game_struct->count_move++);
	}
}

void	ft_keyboard(mlx_key_data_t kd, void *game_struct)
{
	if (kd.key == MLX_KEY_ESCAPE && kd.action == MLX_PRESS)
		exit_game(game_struct);
	if (kd.key == MLX_KEY_W && kd.action == MLX_PRESS)
		ft_movement_y(game_struct, 'u');
	if (kd.key == MLX_KEY_S && kd.action == MLX_PRESS)
		ft_movement_y(game_struct, 'd');
	if (kd.key == MLX_KEY_A && kd.action == MLX_PRESS)
		ft_movement_x(game_struct, 'l');
	if (kd.key == MLX_KEY_D && kd.action == MLX_PRESS)
		ft_movement_x(game_struct, 'r');
	if (kd.action == MLX_PRESS)
	{
		check_items(game_struct);
		check_escape(game_struct);
	}
}
