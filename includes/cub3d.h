/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad <ahmad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:59:11 by ahmad             #+#    #+#             */
/*   Updated: 2024/09/25 10:45:14 by ahmad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "libft"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>


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



#endif