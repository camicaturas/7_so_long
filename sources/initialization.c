/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:14:37 by cberneri          #+#    #+#             */
/*   Updated: 2024/04/15 17:10:56 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_struct *game_struct)
{
	game_struct->fd = 0;
	game_struct->playercount = 0;
	game_struct->exitcount = 0;
	game_struct->collectiblecount = 0;
	game_struct->y = 0;
	game_struct->x = 0;
	game_struct->height = 0;
	game_struct->width = 0;
	game_struct->movecount = 0;
	game_struct->map = NULL;
	game_struct->floor = NULL;
	game_struct->floor_img = NULL;
	game_struct->wall = NULL;
	game_struct->wall_img = NULL;
	game_struct->collectible = NULL;
	game_struct->collectible_img = NULL;
	game_struct->character = NULL;
	game_struct->character_img = NULL;
	game_struct->horse = NULL;
	game_struct->horse_img = NULL;
	game_struct->mlx_ptr = NULL;
}


static int	check_extension(char *str)
{
	char	*ber;
	int		i;
	int		j;

	ber = ".ber";
	i = ft_strlen(str);
	j = 4;
	while (j >= 0)
	{
		if (str[i] != ber[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}

static int	add_line(t_struct *game_struct, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	game_struct->height + 1;
	tmp = malloc(sizeof(char *) * (game_struct->height + 1));
	if (!tmp)
		return (NULL);
	tmp[game_struct->height] = NULL;
	i = 0;
	while (i < game_struct->height - 1)
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
		exit_error(game_struct, 2);
	game_struct->fd = open(map_path, O_RDONLY);
	if (game_struct->fd < 0)
		exit_error(game_struct, 2);
	while (1)
	{
		gnl_readedline = get_next_line(game_struct->fd);
		if (!add_line(game_struct, gnl_readedline))
			break ;
	}
	close(game_struct->fd);
	if (game_struct->map == NULL)
		exit_error(game_struct, 5);
	game_struct->width = get_map_width(game_struct->map[0]);
}
