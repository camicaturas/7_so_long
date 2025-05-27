/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/05/17 11:06:32 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int ac, char **av)
{
	t_struct	game_struct;

	if (ac != 2)
		exit_game_error(&game_struct, 1);
	game_init(&game_struct);
	map_load(&game_struct, av[1]);
	check_map(&game_struct);
	new_window(&game_struct);
	textures_load(&game_struct);
	hooks(&game_struct);
	mlx_loop(game_struct.mlx_ptr);
	exit_game(&game_struct);
}
