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

int	check_extension(char *map_path)
{
	char	*ber;
	int		i;
	int		j;

	ber = ".ber";
	i = ft_strlen(map_path);
	j = 4;

	while (j >= 0)
	{
		if (map_path[i] != ber[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}

int	check_borders(t_struct *game_struct)
{
	int	i;

	i = 0;
	while (game_struct->map_width > i)
	{
		if (game_struct->map[0][i] != '1' || game_struct->map[game_struct->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game_struct->map_height > i)
	{
		if (game_struct->map[i][0] != '1' || game_struct->map[i][game_struct->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_exit(t_struct *game_struct)
{
	if (game_struct->count_exit != 1)
		return (0);
	return (1);
}

int	check_player_spawn(t_struct *game_struct)
{
	if (game_struct->count_player != 1)
		return (0);
	return (1);
}

int	check_count_collectibles(t_struct *game_struct)
{
	if (game_struct->count_collectible < 1)
		return (0);
	return (1);
}