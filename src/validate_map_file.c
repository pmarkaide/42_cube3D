/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:05:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/01 14:07:55 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int check_file_contents(char *file)
{
	int fd;
	char buffer[1];
	ssize_t bytes_read;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf(2, "Error\nCannot open file %s\n", file);
		return (1);
	}
	bytes_read = read(fd, buffer, 1);
	close(fd);
	if (bytes_read <= 0)
	{
		ft_printf(2, "Error\nFile %s is empty or unreadable\n", file);
		return (1);
	}
	return (0);
}

static int	eval_file(char *file, char *ext)
{
	char	*dot;

	if(ft_strcmp(ext,".cub") == 0)
	{
		dot = ft_strrchr(file, '.');
		if(dot == NULL || (dot != NULL && ft_strcmp(dot, ".cub")))
		{
			ft_printf(2, "Error\nWrong file extension\n");
			return (1);
		}
	}
	return check_file_contents(file);
}

static int parse_textures(char *line, t_macro *macro)
{
	char *skipped;

	skipped = ft_skipws(line);
	if(ft_strncmp(skipped, "NO ",3) == 0)
		macro->map->no = ft_strdup(ft_skipws(skipped + 2));
	else if(ft_strncmp(skipped, "SO ",3) == 0)
		macro->map->so = ft_strdup(ft_skipws(skipped + 2));
	else if(ft_strncmp(skipped, "WE ",3) == 0)
		macro->map->we = ft_strdup(ft_skipws(skipped + 2));
	else if(ft_strncmp(skipped, "EA ",3) == 0)
		macro->map->ea = ft_strdup(ft_skipws(skipped + 2));
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
	if (*skipped == '\0' || *skipped == '\n')
		section = 0;
	else if(ft_strncmp(skipped, "NO ",3) == 0)
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
	if(section == 0)
		return(0);
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
			close(fd);
			free(line);
			ft_lstclear(&head, free);
			return (1);
		}
		free(line);
	}
	close(fd);
	macro->map->map = ft_lst_to_array(&head);
	ft_lstclear(&head, free); 
	return (0);
}

static int validate_textures(t_macro *macro)
{
	if (check_file_contents(macro->map->no))
		return (1);
	if (check_file_contents(macro->map->so))
		return (1);
	if (check_file_contents(macro->map->we))
		return (1);
	if (check_file_contents(macro->map->ea))
		return (1);
	return (0);
}

static int validate_colors(int *f, int *c)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (f[i] < 0 || f[i] > 255)
		{
			ft_printf(2, "Error\nFloor color value %d out of range\n", f[i]);
			return (1);
		}
		if (c[i] < 0 || c[i] > 255)
		{
			ft_printf(2, "Error\nCeiling color value %d out of range\n", c[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int validate_contents(t_macro *macro)
{
	if (validate_textures(macro))
		return (1);
	if (validate_colors(macro->map->f, macro->map->c))
		return (1);
	if (validate_map(macro))
		return(1);
	return (0);
}

void	validate_map_file(char *file, t_macro *macro)
{
	if (eval_file(file, ".cub"))
		free_and_exit(macro);
	if (read_file(file, macro))
		free_and_exit(macro);
	print_map_struct(macro->map);
	if (validate_contents(macro))
		free_and_exit(macro);
}
