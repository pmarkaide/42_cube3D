/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:08:42 by dbejar-s          #+#    #+#             */
/*   Updated: 2024/10/31 07:00:42 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "MLX42.h"
# include "../lib/libft/libft.h"

typedef struct	s_macro
{
	int			width;
	int			height;
	char		**map;
	int32_t		floor;
	int32_t		ceiling;
	int			play_x;
	int			play_y;
	char		play_facing; //la direccion en la que mira N, W, E, S
	int			w_map;
	int			h_map;
	mlx_image_t	*img;
	mlx_t		*mlx_cub;
}	t_macro;

#endif