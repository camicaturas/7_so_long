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

#include "so_long.h"

//int32_t	main(int ac, char **av)
int32_t	main(void)
{
	t_struct	game_struct;

//	if (ac != 2)
//		exit_error(&game_struct, 1);
	game_init(&game_struct);
	//map_load(&game_struct, av[1]);
	map_load(&game_struct, "/Users/cami/CAMI/Programacion/Core/7_so_long/assets/maps/test.ber");
	check_map(&game_struct);
	new_window(&game_struct);
	textures_load(&game_struct);
	hooks(&game_struct);
	printf("player position INICIAL (X,Y): %i %i\n", game_struct.player_x, game_struct.player_y);

	mlx_loop(game_struct.mlx_ptr);
	exit_game(&game_struct);

}


/*
// comando para mac
//gcc main2.c ../lib/MLX42//build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
//gcc main.c controller_error.c controller_map.c initialization.c so_long.h ../lib/MLX42//build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/"
//gcc main.c controller_error.c controller_map.c initialization.c so_long.h ../lib/MLX42//build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/" -framework Cocoa -framework OpenGL -framework IOKit
*/