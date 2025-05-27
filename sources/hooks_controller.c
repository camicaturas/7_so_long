/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/05/14 11:01:42 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectibles(t_struct *game_struct)
{
	return (game_struct->count_collectible);
}

void	check_items(t_struct *game_struct)
{
	size_t	i;

	if (game_struct->map[game_struct->player_y][game_struct->player_x] == 'c')
	{
		game_struct->map[game_struct->player_y][game_struct->player_x] = 'x';
		i = 0;
		while (i < game_struct->collectible_img->count)
		{
			if (game_struct->player_y * game_struct->map_tile_height
				== game_struct->collectible_img->instances[i].y
				&& game_struct->player_x * game_struct->map_tile_width
				== game_struct->collectible_img->instances[i].x)
				game_struct->collectible_img->instances[i].enabled = false;
			i++;
		}
		game_struct->count_collectible--;
		ft_printf("%i Mana pots remaining.\n", game_struct->count_collectible);
	}
}

void	check_escape(t_struct *game_struct)
{
	if (game_struct->map[game_struct->player_y]
		[game_struct->player_x] == 'e')
	{
		if (check_collectibles(game_struct) == 0)
		{
			ft_printf("Congrats! You have escaped the Dungeon!\n");
			exit_game(game_struct);
		}
		else
			ft_printf("Collect all Mana pots to escape the Dungeon!!\n");
	}
}

void	hooks(t_struct *game_struct)
{
	mlx_key_hook(game_struct->mlx_ptr, ft_keyboard, game_struct);
}

/*
	//mlx_loop_hook(game_struct->mlx_ptr, hook_player_position, game_struct);
	//mlx_put_string(game_struct->mlx_ptr, "Pos:", 10, 10);
	//mlx_image_t* mlx_put_string(mlx_t* mlx,
		const char* str, int32_t x, int32_t y);
*/