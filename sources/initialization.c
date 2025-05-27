/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/05/17 11:10:38 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_struct *game_struct)
{
	game_struct->fd = 0;
	game_struct->player_x = 0;
	game_struct->player_y = 0;
	game_struct->count_player = 0;
	game_struct->count_exit = 0;
	game_struct->count_collectible = 0;
	game_struct->count_move = 0;
	game_struct->screen_width = 1920;
	game_struct->screen_height = 1080;
	game_struct->map_width = 0;
	game_struct->map_height = 0;
	game_struct->map_tile_width = 64;
	game_struct->map_tile_height = 64;
	game_struct->map = NULL;
	game_struct->player_img = NULL;
	game_struct->wall_img = NULL;
	game_struct->collectible_img = NULL;
	game_struct->floor_img = NULL;
	game_struct->exit_img = NULL;
	game_struct->player = NULL;
	game_struct->wall = NULL;
	game_struct->collectible = NULL;
	game_struct->floor = NULL;
	game_struct->exit = NULL;
	game_struct->mlx_ptr = NULL;
}

static int	add_row(t_struct *game_struct, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	game_struct->map_height++;
	tmp = malloc(sizeof(char *) * (game_struct->map_height + 1));
	if (!tmp)
		return (1);
	tmp[game_struct->map_height] = NULL;
	i = 0;
	while (game_struct->map_height - 1 > i)
	{
		tmp[i] = game_struct->map[i];
		i++;
	}
	tmp[i] = line;
	if (game_struct->map)
		free(game_struct->map);
	game_struct->map = tmp;
	return (1);
}

void	map_load(t_struct *game_struct, char *map_path)
{
	char	*gnl_readedline;

	if (!check_extension(map_path))
		exit_more_map_error(game_struct, 3);
	game_struct->fd = open(map_path, O_RDONLY);
	if (game_struct->fd < 0)
		exit_game_error(game_struct, 2);
	while (1)
	{
		gnl_readedline = get_next_line(game_struct->fd);
		if (!add_row(game_struct, gnl_readedline))
			break ;
	}
	close(game_struct->fd);
	if (game_struct->map == NULL)
		exit_game_error(game_struct, 5);
	game_struct->map_width = map_width(game_struct->map[0]);
}
