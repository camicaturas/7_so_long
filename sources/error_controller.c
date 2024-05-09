/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/04/15 17:10:56 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_struct *game_struct, int num)
{
	if (num == 1)
		ft_printf("Error: Not enough arguments\n");
	else if (num == 2)
		ft_printf("Error: Invalid file descriptor or map extension\n");
	else if (num == 3)
		ft_printf("Error: Invalid map or Map borders not closed\n");
	else if (num == 4)
	{
		ft_printf("Error: Loading textures failed\n");
		mlx_terminate(game_struct->mlx_ptr);
	}
	else if (num == 5)
		ft_printf("Error: Empty file\n");
	else if (num == 9)
		ft_printf("Error: Oversized tiles, check game_init()\n");
	map_free(game_struct->map);
	exit(EXIT_FAILURE);
}

void	exit_game_error(t_struct *game_struct, int num)
{
	if (num == 6)
		ft_printf("Error: There's no Player spawn in the Map\n");
	else if (num == 7)
		ft_printf("Error: There's no Exit in the Map\n");
	else if (num == 8)
		ft_printf("Error: There's no Collectibles in the Map\n");
	map_free(game_struct->map);
	exit(EXIT_FAILURE);
}