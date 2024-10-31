/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:05:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/10/31 08:43:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int eval_file(argv[1])
// confirm the extension .cub
// file = open(argv[1])
// else return error

// int read_file(argv[1])
// line = get_next_line(fd)
// skip_whitespaces
// get_first chars
// eval if they are correct (from list and from existing)
// if good skip_whitespaces, save
// else error

// int eval_textures(map)
// eval_file(texture_file)
// else error

// int eval_colors(map)
// int in range 0-255

// int eval_map(map)
// correct chars
// spaces to walls
// surrounded by walls

// int eval_elements(map)
// eval textures
// eval colors
// eval map

static int	eval_file(char *file, char *ext)
{
	char	*dot;
	int fd;

	if(ext == ".cub")
	{
		dot = ft_strrchr(file, '.');
		if(dot == NULL || (dot != NULL && ft_strcmp(dot, ".cub")))
		{
			ft_printf(2, "Error\nWrong file extension\n");
			return (1);
		}
	}
	fd = open(file, O_RDONLY);
	if(fd == -1)
	{
		ft_printf(2, "Error\nCannot open file %s\n", file);
		return (1);
	}
	return(0);
}

void	validate_map(char *file, t_macro *macro)
{
	if (eval_file(file, ".cub"))
		free_and_exit(macro);
	// if (read_file(file, macro))
	// 	free_and_exit(macro);
	// if (validate_contents(macro))
	// 	free_and_exit(macro);
}
