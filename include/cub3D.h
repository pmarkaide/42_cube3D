/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:42 by dbejar-s          #+#    #+#             */
/*   Updated: 2024/10/31 11:57:19 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include "MLX42.h"
# include "../lib/libft/libft.h"

# define BLOCK 32 // size of each block
# define ANGLE_VIEW 60 // Angle View for the Player
# define RATIO_SCREEN 0.75

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct	s_macro
{
	int			width;
	int			height;
	char		**map;
	int32_t		floor;
	int32_t		ceiling;
	int			play_x;
	int			play_y;
	int			pos_pl_x;
	int			pos_pl_y;
	char		play_facing; //la direccion en la que mira N, W, E, S
	int			w_map;
	int			h_map;
	mlx_image_t	*img;
	mlx_t		*mlx_cub;
}	t_macro;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
char** parse_map(const char* filename, int* rows, int* cols);
void ft_hook(mlx_key_data_t keydata, void *param);

#endif