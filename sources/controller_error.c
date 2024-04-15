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

void	exit_error(t_struct *game, int num)
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
	else if (num == 3)
		ft_printf("Error: Invalid map\n");
	else if (num == 4)
	{
		ft_printf("Error: Loading textures failed\n");
		mlx_terminate(game->mlx_ptr);
	}
	else if (num == 5)
	{
		ft_printf("Error: Empty file\n");
		exit(EXIT_FAILURE);
	}
	free_map(game->map);
	exit(EXIT_FAILURE);
}