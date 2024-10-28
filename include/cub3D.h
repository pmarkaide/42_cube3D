/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:42 by dbejar-s          #+#    #+#             */
/*   Updated: 2024/10/28 12:25:16 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42.h"

# define WIDTH 512
# define HEIGHT 512

typedef struct	s_mlx
{
	mlx_image_t		*img;
	mlx_t			*mlx_cub;
}	t_mlx;


typedef struct	s_macro
{
	char	**map;
	int		play_x;
	int		play_y;
	char	play_facing; //la direccion en la que mira N, W, E, S
	int		w_map;
	int		h_map;
	t_mlx	*m_mlx;
	
}	t_macro;

#endif