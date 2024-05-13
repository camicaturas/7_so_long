/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/04/15 13:41:52 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_valid(t_struct *game_struct)
{
	int	i;
	int	j;

	j = 0;
	while (game_struct->map[j])
	{
		i = 0;
		while (game_struct->map[j][i] != '\0' && game_struct->map[j][i] != '\n')
		{
			if ((game_struct->map[j][i] != 'C' && game_struct->map[j][i] != 'P'
				&& game_struct->map[j][i] != 'E' && game_struct->map[j][i] != '1'
				&& game_struct->map[j][i] != '0') || i >= game_struct->map_width)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	flood_fill_check(t_struct *game_struct, int y, int x)
{
	if (game_struct->map[y][x] == 'C')
	{
		game_struct->map[y][x] = 'c';
		game_struct->count_collectible++;
	}
	else if (game_struct->map[y][x] == 'P')
	{
		game_struct->map[y][x] = 'p';
		game_struct->count_player++;
	}
	else if (game_struct->map[y][x] == 'E')
	{
		game_struct->map[y][x] = 'e';
		game_struct->count_exit++;
	}
	else if (game_struct->map[y][x] == '0')
	{
		game_struct->map[y][x] = '2';
	}
}

void	flood_fill(int y, int x, t_struct *game_struct)
{
	if (x < 0 || y < 0 || x >= game_struct->map_width || y >= game_struct->map_height)
		return ;
	else if (game_struct->map[y][x] != '0' && game_struct->map[y][x] != 'C'
		&& game_struct->map[y][x] != 'P' && game_struct->map[y][x] != 'E')
		return ;
	flood_fill_check(game_struct, y, x);
	flood_fill(y, x - 1, game_struct);
	flood_fill(y, x + 1, game_struct);
	flood_fill(y - 1, x, game_struct);
	flood_fill(y + 1, x, game_struct);
}