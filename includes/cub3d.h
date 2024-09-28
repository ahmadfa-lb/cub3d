/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:59:11 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/28 20:22:21 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# define M_PI 3.14159265358979323846

# define EXPECTED_SETTING_PARTS 2 // identifier -> value
# define BASE_SETTINGS_REQUIRED 6 // TEXTURES PATH, FLOOR AND CEILING COLORS
# define ARGUMENTS_REQUIRED 2
# define FILE_EXTENTION ".cub"
# define NBR_OF_ERRORS 20
# define FRAME "./game_data/textures/minimap_frame.xpm"
//=== Keys ----------------------------------------------------------------===//

# define KEY_COUNT 6
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define E 101

//=== Colors --------------------------------------------------------------===//

# define WHITE 0xffffff
# define GREY 0x808080
# define RED 0xff0000
# define BLACK 0x000000
# define GREEN 0x00FF00

//=== Minimap -------------------------------------------------------------===//

# define PLAYER_DOT_SIZE 4.0f
# define MINIMAP_SIZE 200.0f
# define RANGE 5.0f

//=== Player Settings -----------------------------------------------------===//

# define FOV 60.0f
# define SENSITIVITY 5
# define MOUSE_SENSITIVITY 0.015f
# define TRESHOLD 10
# define STRAFE_SPEED 0.1f
# define PLAYER_SPEED 0.2f
# define HIT_BOX 0.2f
# define MAX_DOOR_INTERACT_DISTANCE 1.7f

typedef void	(*t_exit_func_ptr)(void);

typedef struct s_bresenham
{
	int	dx_dy[2];
	int	sx_sy[2];
	int	err;
	int	e2;
}	t_bresenham;

typedef enum s_errors
{
	SUCCESS,
	MLX_ERROR,
	BAD_ARGUMENTS,
	MISSING_SETTING,
	E_BAD_FILE_PATH,
	N_BAD_FILE_PATH,
	S_BAD_FILE_PATH,
	W_BAD_FILE_PATH,
	DUPLICATED_SETTING,
	BAD_SETTING_FORMAT,
	BAD_COLOR_CODE_FORMAT,
	BAD_FILE_EXTENTION,
	BAD_IDENTIFIER,
	MAP_MISSING,
	MAP_UNCLOSED,
	MAP_WRONG_CHARACTER,
	MAP_MISSING_PLAYER_SPAWN_POS,
	MAP_DUPLICATED_PLAYER_SPAWN_POS,
	NO_MAP_IN_FILE,
	OTHER
}	t_errors;

typedef enum e_key
{
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D,
	KEY_LEFT,
	KEY_RIGHT
}	t_key;

typedef struct s_keys
{
	bool	keys[KEY_COUNT];
}	t_keys;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_minimap
{
	int		cell_width;
	int		cell_height;
	t_img	frame;
}	t_minimap_data;

typedef struct s_cub_utils
{
	int						argc;
	char					**argv;
	char					*map_path;
	int						settings_already_set;
	int						map_width;
	int						map_height;
	struct s_minimap		minimap;
	t_exit_func_ptr			exit_funcs[NBR_OF_ERRORS];
}	t_cub_utils;

typedef struct s_cub_settings
{
	char			*e_texture_path;
	char			*n_texture_path;
	char			*s_texture_path;
	char			*w_texture_path;
	struct s_color	*ceiling_color;
	struct s_color	*floor_color;
	char			**map;
}	t_cub_settings;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		win_height;
	int		win_width;
	int		bits;
	int		line_len;
	int		edian;
}	t_mlx;



typedef struct s_player_data
{
	float			x;
	float			y;
	float			mm_x;
	float			mm_y;
	float			angle;
	char			pole;
}	t_player_data;

typedef struct s_walls
{
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_img	door;
}	t_walls;

typedef struct s_ray_cast
{
	int		column; // the pixel column we are casting the ray on	
	float	ray_angle;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		side; // side of the wall hit 0 = vertical line, 1 = horizontal line
	float	raw_wall_dist;
	float	perp_wall_dist;
	int		line_draw_start;
	int		line_draw_end;
	int		texture_x;
	int		texture_y;
	int		line_height;
	bool	door_hit;
	bool	player_facing_door;
	int		x_faced_door;
	int		y_faced_door;
	bool	hit;
}	t_ray_cast;

typedef struct s_cub3d_data
{
	struct s_cub_settings	settings;
	struct s_cub_utils		utils;
	struct s_mlx			mlx;
	struct s_player_data	player_data;
	struct s_ray_cast		ray;
	struct s_walls			walls;
	struct s_keys			keys;
}	t_cub3d_data;




typedef struct s_map_params // Specific struct helping for map parsing
{
	char		**old_map;
	char		*line;
	int			fd;
	t_cub3d_data	*cub_data;
}	t_map_params;



void	cub3d_exit(t_errors exit_code, t_cub3d_data *data);
void	check_file_extension(struct s_cub3d_data *data);
void	parsing(struct s_cub3d_data *data);
int		store_texture_path(t_cub3d_data *data, char **line_elements, int fd);
void	store_map(t_cub3d_data *data, char *old_line, int fd);
int		store_colors(t_cub3d_data *data, char **line_elements, int fd, char id);
void	free_double_array(char ***array_ptr);
void	reach_eof_to_avoid_leaks(char *line, int fd);
int		double_array_len(char **dArray);
void	check_map_validity(t_cub3d_data *data, int fd);

void	init_data(struct s_cub3d_data *data);
void	get_imgs_addr(t_cub3d_data *data);
void	load_mlx(t_cub3d_data *data);


void	bad_setting_format_error(void);
void	other_msg(void);
void	bad_file_extention_msg(void);
void	bad_arguments_msg(void);
void	duplicated_setting_error(void);
void	east_bad_file_path_error(void);
void	north_bad_file_path_error(void);
void	south_bad_file_path_error(void);
void	west_bad_file_path_error(void);
void	bad_identifier_error(void);
void	bad_color_code_format_error(void);
void	missing_setting_error(void);
void	missing_map_error(void);
void	unclosed_map_error(void);
void	mlx_error(void);
void	map_wrong_character_error(void);
void	map_duplicated_player_spawn_pos(void);
void	map_missing_player_spawn_pos(void);
void	map_missing(void);
void	cub_exit_success(void);



#endif