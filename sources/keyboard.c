/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/04/15 13:41:52 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
char *check_asset_collision(t_struct *game_struct)
{
	if(game_struct->map[game_struct->player_y]
		[game_struct->player_x] == '1')
		return "1";
	else if (game_struct->map[game_struct->player_y]
		[game_struct->player_x] == 'c')
		return "c";
	else if (game_struct->map[game_struct->player_y]
		[game_struct->player_x] == 'e')
		return "e";
	else if (game_struct->map[game_struct->player_y]
		[game_struct->player_x] == 'p')
		return "p";
	else if (game_struct->map[game_struct->player_y]
		[game_struct->player_x] == '2' || 
		game_struct->map[game_struct->player_y]
		[game_struct->player_x] == '0')
		return "0";
	return(NULL) ;
}
	if (ft_strcmp(check_asset_collision(game_struct, game_struct->map[game_struct->player_y-1][game_struct->player_x]), "1") == 0)
		return ;

*/

void ft_movement_y(t_struct *game_struct, char direction)
{
	if (direction == 'u')
	{
		if(game_struct->map[game_struct->player_y-1][game_struct->player_x] == '1')
			return ;
		game_struct->player_img->instances[0].y -= game_struct->map_tile_height;
		game_struct->player_y -= 1;
		//printf("player (X,Y): %i %i\n",game_struct->player_x,game_struct->player_y);

	}		
	if (direction == 'd')
	{
		if(game_struct->map[game_struct->player_y+1][game_struct->player_x] == '1')
			return ;
		game_struct->player_img->instances[0].y += game_struct->map_tile_height;
		game_struct->player_y += 1;
	}
}

void ft_movement_x(t_struct *game_struct, char direction)
{
	if (direction == 'l')
	{
		if(game_struct->map[game_struct->player_y][game_struct->player_x-1] == '1')
			return ;
		game_struct->player_img->instances[0].x -= game_struct->map_tile_height;
		game_struct->player_x -= 1;
	}
	if (direction == 'r')
	{
		if(game_struct->map[game_struct->player_y][game_struct->player_x+1] == '1')
			return ;
		game_struct->player_img->instances[0].x += game_struct->map_tile_height;
		game_struct->player_x += 1;
	}
}

void	ft_keyboard(mlx_key_data_t kd, void *game_struct)
{
	if (kd.key == MLX_KEY_ESCAPE && kd.action == MLX_PRESS)
		exit_game(game_struct);
	if (kd.key == MLX_KEY_UP && kd.action == MLX_PRESS)
		ft_movement_y(game_struct, 'u');	
	if (kd.key == MLX_KEY_DOWN && kd.action == MLX_PRESS)
		ft_movement_y(game_struct, 'd');	
	if (kd.key == MLX_KEY_LEFT && kd.action == MLX_PRESS)
		ft_movement_x(game_struct, 'l');	
	if (kd.key == MLX_KEY_RIGHT && kd.action == MLX_PRESS)
		ft_movement_x(game_struct, 'r');
	if (kd.action == MLX_PRESS)
	{
		check_items(game_struct);
		check_escape(game_struct);
	}
}