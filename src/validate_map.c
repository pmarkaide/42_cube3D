/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:05:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/10/31 14:11:42 by pmarkaid         ###   ########.fr       */
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

	if(ft_strcmp(ext,".cub") == 0)
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


int parse_textures(char *line, t_macro *macro)
{
	if(ft_strncmp(line, "NO",2) == 0)
		macro->map->no = ft_strdup(ft_skipws(line + 2));
	else if(ft_strncmp(line, "SO",2) == 0)
		macro->map->so = ft_strdup(ft_skipws(line + 2));
	else if(ft_strncmp(line, "WE",2) == 0)
		macro->map->we = ft_strdup(ft_skipws(line + 2));
	else if(ft_strncmp(line, "EA",2) == 0)
		macro->map->ea = ft_strdup(ft_skipws(line + 2));
	return(0);
}

// int parse_colors(char *line, t_macro *macro)
// {
// 	else if(ft_strncmp(line, "F",1) == 0)
// 	{
// 		macro->map->f[0] = ft_atoi(ft_skipws(line + 1));
// 		macro->map->f[1] = ft_atoi(ft_skipws(line + 3));
// 		macro->map->f[2] = ft_atoi(ft_skipws(line + 5));
// 	}
// 	else if(ft_strncmp(line, "C",1) == 0)
// 	{
// 		macro->map->c[0] = ft_atoi(ft_skipws(line + 1));
// 		macro->map->c[1] = ft_atoi(ft_skipws(line + 3));
// 		macro->map->c[2] = ft_atoi(ft_skipws(line + 5));
// 	}
// }

int detect_section(char *line)
{
	char *skipped;
	int section;

	skipped = ft_skipws(line);
	if(ft_strncmp(skipped, "NO",2) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "SO",2) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "WE",2) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "EA",2) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "F",1) == 0)
		section= 2;
	else if(ft_strncmp(skipped, "C",1) == 0)
		section= 2;
	else
		section= 3;
	return(section);
}

int parse_line(char *line, t_macro *macro, int section)
{
	int err;

	err = 0;
	if(section == 1)
		err = parse_textures(line, macro);
	return(err);
}

int read_file(char *file, t_macro *macro)
{
	char *line;
	int fd;
	int section;
	
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		section = detect_section(line);
		if (parse_line(line, macro, section))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	return (0);
}

void	validate_map(char *file, t_macro *macro)
{
	if (eval_file(file, ".cub"))
		free_and_exit(macro);
	if (read_file(file, macro))
		free_and_exit(macro);
	print_map_struct(macro->map);
	// if (validate_contents(macro))
	// 	free_and_exit(macro);
}
