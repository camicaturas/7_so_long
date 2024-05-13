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

void	player_spawn_position(t_struct *game_struct)
{
	while (game_struct->map[game_struct->player_y])
	{
		game_struct->player_x = 0;
		while (game_struct->map[game_struct->player_y][game_struct->player_x])
		{
			if (game_struct->map[game_struct->player_y][game_struct->player_x] == 'P')
				return ;
			game_struct->player_x++;
		}
		game_struct->player_y++;
	}
}

char	**player_current_position(t_struct *game_struct)
{
	char **position;
	position = NULL;
	position[0][0] = game_struct->player_y;
	position[0][1] = game_struct->player_x; 
	return position;
}