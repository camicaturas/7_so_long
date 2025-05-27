/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/05/17 11:05:38 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game_error(t_struct *game_struct, int num)
{
	if (num == 1)
	{
		ft_printf("Error: Not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 2)
	{
		ft_printf("Error: Invalid file descriptor or map extension\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 4)
	{
		ft_printf("Map Error: Loading textures failed\n");
		mlx_terminate(game_struct->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	else if (num == 5)
	{
		ft_printf("Error: Empty file\n");
		exit(EXIT_FAILURE);
	}
	map_free(game_struct->map);
	exit(EXIT_FAILURE);
}

void	exit_map_error(t_struct *game_struct, int num)
{
	if (num == 6)
	{
		ft_printf("Map Error: There's no Player spawn in the Map\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 7)
	{
		ft_printf("Map Error: There's no Exit in the Map\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 8)
	{
		ft_printf("Map Error: There's no Collectibles in the Map\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 10)
	{
		ft_printf("Map Error: Map is not rectangular\n");
		exit(EXIT_FAILURE);
	}
	map_free(game_struct->map);
	exit(EXIT_FAILURE);
}

void	exit_more_map_error(t_struct *game_struct, int num)
{
	if (num == 3)
	{
		ft_printf("Map Error: Invalid map or Map borders not closed\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 9)
	{
		ft_printf("Map Error: Tiles too big! Doesn't fit in the screen\n");
		exit(EXIT_FAILURE);
	}
	map_free(game_struct->map);
	exit(EXIT_FAILURE);
}
