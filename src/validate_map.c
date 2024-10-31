/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:05:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/10/31 17:46:50 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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


static int parse_textures(char *line, t_macro *macro)
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

static  int parse_colors(char *line, t_macro *macro)
{
	char *skipped;
	int i;

	i = -1;
	skipped = ft_skipws(line);
	skipped = ft_skipws(skipped + 1);
	while(++i < 3)
	{
		if(ft_skipws(line)[0] == 'F')
			macro->map->f[i] = ft_atoi(skipped);
		else if(ft_skipws(line)[0]  == 'C')
			macro->map->c[i] = ft_atoi(skipped);
		skipped = ft_strchr(skipped, ',');
		if(skipped)
			skipped++;
	}
	return(0);
}

static int detect_section(char *line)
{
	char *skipped;
	int section;

	skipped = ft_skipws(line);
	if(ft_strncmp(skipped, "NO ",3) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "SO ",3) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "WE ",3) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "EA ",3) == 0)
		section= 1;
	else if(ft_strncmp(skipped, "F ",2) == 0)
		section= 2;
	else if(ft_strncmp(skipped, "C ",2) == 0)
		section= 2;
	else
		section= 3;
	return(section);
}

static int parse_map(char *line, t_list **head)
{
	t_list *new;

	new = ft_lstnew(ft_strdup(line));
	if (!new)
		return (1);
	ft_lstadd_back(head, new);
	return (0);
}

static int parse_line(char *line, t_macro *macro, int section, t_list **head)
{
	int err;

	err = 0;
	if(section == 1)
		err = parse_textures(line, macro);
	if(section == 2)
		err = parse_colors(line, macro);
	if(section == 3)
		err = parse_map(line, head);
	return(err);
}

static int read_file(char *file, t_macro *macro)
{
	char *line;
	int fd;
	int section;
	t_list *head = NULL;
	
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		section = detect_section(line);
		if (parse_line(line, macro, section, &head))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
	}
	close(fd);
	macro->map->map = ft_lst_to_array(&head);
	ft_lstclear(&head, free); 
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
