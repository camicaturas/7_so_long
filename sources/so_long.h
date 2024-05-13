/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:12:05 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/04/15 17:10:55 by cberneri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#endif


// BORRARRR ESTO LUEGO, get next line y buffer size
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#endif

//// de aca para arriba

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_struct
{
	int				fd;
	int				player_x;
	int				player_y;
	int				count_player;
	int				count_exit;
	int				count_collectible;
	int				count_move;
	int				screen_width;
	int				screen_height;
	int				map_width;
	int				map_height;
	int				map_tile_width;
	int				map_tile_height;
	char			**map;
	char			*game_title;
	mlx_image_t		*player_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*collectible_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*exit_img;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_t			*mlx_ptr;
}	t_struct;

//void	check_asset_collision(int **player_position);
int		check_borders(t_struct *game_struct);
int		check_counts(t_struct *game_struct);
int		check_collectibles(t_struct *game_struct);
int		check_extension(char *map_path);
void	check_escape(t_struct *game_struct);
int		check_exit(t_struct *game_struct);
void	check_items(t_struct *game_struct);
int		check_player_spawn(t_struct *game_struct);
int		check_count_collectibles(t_struct *game_struct);
void	check_map(t_struct *game_struct);
void	exit_game(t_struct *game_struct);
void	exit_error(t_struct *game_struct, int num);
void	exit_game_error(t_struct *game_struct, int num);
void	flood_fill(int y, int x, t_struct *game_struct);
void	flood_fill_check(t_struct *game_struct, int y, int x);
void	ft_movement_y(t_struct *game_struct, char direction);
void	ft_movement_x(t_struct *game_struct, char direction);
void	game_init(t_struct *game_struct);
void	load_all_textures(t_struct *game_struct);
void	map_load(t_struct *game_struct, char *map_path);
void	map_free(char **map);
int		map_valid(t_struct *game_struct);
int		map_width(char *line);
int		new_window(t_struct *game_struct);
char	**player_current_position(t_struct *game_struct);
void	player_spawn_position(t_struct *game_struct);
void	textures_load(t_struct *game_struct);

//hooks
void	hooks(t_struct *game_struct);
void	ft_keyboard(mlx_key_data_t keydata, void *ptr);

//get next line
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_readed_line(char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_move_start(char *start);
char	*ft_strjoin(char *s1, char *s2);

//printf
int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printdigit(long n, int base, int uppercase);
int	ft_printptr(unsigned long long ptr);
int	ft_printstr(char *str);

//ft_strcmp (volver a compilar LIBFT con esta funcion porque esta afuera)
int	ft_strcmp(char *s1, char *s2);







////////////////////////////////////

/////////////////


//ESTO ES PARA PROBAR EL EJEMPLO de animacion, borrar luego





typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;	
	int		height;	
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

/*Window and Images*/
t_win	new_window2(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);


typedef struct {
        int a;
        char b;
}       simple_struct;

typedef struct s_list
{
	simple_struct			*content;
	struct s_list	*next;
}		t_list;


typedef struct s_animation {
  t_list*   frames;
  int       frame_speed;        // The speed of the animation in miliseconds
  double    accum;              // The accumulator to controll the speed
  int       current_frame_num;  // Which frame is selected
  int       mirrored;
  long int  frame_count;        // The frame count
} t_animation;

typedef struct sprite_slice {
  int x;
  int y;
  int width;
  int height;
  int padding_x;
  int padding_y;
} sprite_slice;

typedef struct s_sprite {
  mlx_image_t*  sprite_img;
  mlx_t*        mlx;
} t_sprite;

/* SPRITES */
t_sprite      new_sprite(char* file_name, mlx_t* mlx);
t_animation*  slice_sprite(t_sprite* s, sprite_slice slice, int mirrored, int frames, int delay);
void          destroy_sprite(t_sprite* s);


//Funciones que deberian estar dentro de LIBFT
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));



