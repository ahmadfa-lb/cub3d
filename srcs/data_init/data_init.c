/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:20:20 by afarachi          #+#    #+#             */
/*   Updated: 2024/09/27 14:23:46 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_null_to_ptrs(t_cub3d_data *data)
{
	// data->gun.shoot1.img_ptr = NULL;
	// data->gun.shoot2.img_ptr = NULL;
	// data->gun.shoot3.img_ptr = NULL;
	// data->gun.std.img_ptr = NULL;
	// data->gun.std2.img_ptr = NULL;
	// data->gun.std3.img_ptr = NULL;
	// data->gun.std4.img_ptr = NULL;
	data->mlx.mlx_ptr = NULL;
	data->mlx.img = NULL;
	data->mlx.win_ptr = NULL;
	data->keys.keys[0] = false;
	data->keys.keys[1] = false;
	data->keys.keys[2] = false;
	data->keys.keys[3] = false;
	data->keys.keys[4] = false;
	data->keys.keys[5] = false;
	data->walls.east.img_ptr = NULL;
	data->walls.north.img_ptr = NULL;
	data->walls.south.img_ptr = NULL;
	data->walls.west.img_ptr = NULL;
	data->walls.door.img_ptr = NULL;
	// data->gun.shoot_frame = 0;
	// data->gun.is_shooting = false;
	// data->gun.last_shoot_time = 0;
	data->walls.door.img_ptr = NULL;
}


static void	init_exit_functions_array(struct s_cub3d_data *data)
{
	data->utils.exit_funcs[0] = cub_exit_success;
	data->utils.exit_funcs[1] = mlx_error;
	data->utils.exit_funcs[2] = bad_arguments_msg;
	data->utils.exit_funcs[3] = missing_setting_error;
	data->utils.exit_funcs[4] = east_bad_file_path_error;
	data->utils.exit_funcs[5] = north_bad_file_path_error;
	data->utils.exit_funcs[6] = south_bad_file_path_error;
	data->utils.exit_funcs[7] = west_bad_file_path_error;
	data->utils.exit_funcs[8] = duplicated_setting_error;
	data->utils.exit_funcs[9] = bad_setting_format_error;
	data->utils.exit_funcs[10] = bad_color_code_format_error;
	data->utils.exit_funcs[11] = bad_file_extention_msg;
	data->utils.exit_funcs[12] = bad_identifier_error;
	data->utils.exit_funcs[13] = map_missing;
	data->utils.exit_funcs[14] = unclosed_map_error;
	data->utils.exit_funcs[15] = map_wrong_character_error;
	data->utils.exit_funcs[16] = map_missing_player_spawn_pos;
	data->utils.exit_funcs[17] = map_duplicated_player_spawn_pos;
	data->utils.exit_funcs[18] = missing_map_error;
	data->utils.exit_funcs[19] = other_msg;
}

static void	init_cub_data(struct s_cub3d_data *data)
{
	data->utils.settings_already_set = 0;
	data->settings.ceiling_color = NULL;
	data->settings.floor_color = NULL;
	data->settings.e_texture_path = NULL;
	data->settings.n_texture_path = NULL;
	data->settings.s_texture_path = NULL;
	data->settings.w_texture_path = NULL;
	data->settings.map = NULL;
	data->utils.map_path = NULL;
	data->mlx.mlx_ptr = NULL;
	data->mlx.win_ptr = NULL;
	data->mlx.img = NULL;
	data->mlx.addr = NULL;
	data->walls.east.img_ptr = NULL;
	data->walls.west.img_ptr = NULL;
	data->walls.north.img_ptr = NULL;
	data->walls.south.img_ptr = NULL;
	data->utils.minimap.cell_width = MINIMAP_SIZE / (2 * RANGE);
	data->utils.minimap.cell_height = MINIMAP_SIZE / (2 * RANGE);
}

void	init_data(struct s_cub3d_data *data)
{
	init_cub_data(data);
	init_exit_functions_array(data);
	set_null_to_ptrs(data);
}
