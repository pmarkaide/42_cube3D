/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:10:04 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/10/29 15:59:45 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_macro *macro)
{
	if (macro->map)
	{
		if (macro->map->no)
			free(macro->map->no);
		if (macro->map->so)
			free(macro->map->so);
		if (macro->map->we)
			free(macro->map->we);
		if (macro->map->ea)
			free(macro->map->ea);
		if (*macro->map->f)
			free(macro->map->f);
		if (*macro->map->c)
			free(macro->map->c);
		if (macro->map->map)
			free(macro->map->map);
		free(macro->map);
	}
}

void	free_macro(t_macro *macro)
{
	free_map(macro);
	if (macro->m_mlx)
	{
		mlx_delete_image(macro->m_mlx->mlx_cub, macro->m_mlx->img);
		mlx_close_window(macro->m_mlx->mlx_cub);
		mlx_terminate(macro->m_mlx->mlx_cub);
	}
	free(macro);
}

void	free_and_exit(t_macro *macro)
{
	write(2, "Error\n", 6);
	free_macro(macro);
	exit(1);
}
