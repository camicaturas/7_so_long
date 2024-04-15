/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/04/15 17:10:54 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../lib/MLX42/include/MLX42/MLX42.h"
//#include "so_long.h"

#define WIDTH 1440
#define HEIGHT 810

int32_t	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(&game, 1);
	game_init(&game);
	map_load(&game, av[1]);







	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Main PROGRAMAIDANDKADAD", false);
	if (!mlx)
		error();

	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);

	// Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	

	
/*
  // Try to load the file
	mlx_texture_t* texture = mlx_load_png("assets/textures/menu_hard.png");
	if (!texture)
		error();

// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);

	// Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
*/

}
