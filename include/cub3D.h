/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:42 by dbejar-s          #+#    #+#             */
/*   Updated: 2024/11/01 23:32:42 by dbejar-s         ###   ########.fr       */
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

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define BLOCK 32 // size of each block
# define ANGLE_VIEW 60 // Angle View for the Player
/* Standard POV is 90, narrow POV is 60, wide POV is 120*/
# define RATIO_SCREEN 0.75
# define TWO_PI (2 * M_PI)
# define A_DEG 180 / M_PI
# define A_RAD M_PI / 180


typedef struct	s_macro
{
	int			width;
	int			height;
	char		**map;
	char		orientation; //N, W, E, S
	int32_t		floor;
	int32_t		ceiling;
	int32_t		wall;
	int			start_x;
	int			start_y;
	int			pos_pl_x;
	int			pos_pl_y;
	float		play_view;
	double		play_angle;
	char		play_facing; //la direccion en la que mira N, W, E, S
	int			w_map;
	int			h_map;
	double		distance;
	double		line_angle;
	mlx_image_t	*img;
	mlx_t		*mlx_cub;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int 		map_x;
	int 		map_y;
	double		side_dist_x;
    double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int32_t		wall_color;
}	t_macro;

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
char** 	parse_map(const char* filename, int* rows, int* cols);
void	ft_hook(mlx_key_data_t keydata, void *param);
void	load_game(t_macro *macro);
void	print_map(t_macro *macro);
void	calculate_wall_distance(t_macro *macro);
void	draw_wall_slice(t_macro *macro, int x);
void	paint_wall(t_macro *macro);
void	paint_background(t_macro *macro);
void	calculate_ray_direction(t_macro *macro, int x);
void	calculate_step_and_side_dist(t_macro *macro);
void	perform_dda(t_macro *macro);

#endif