/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:59:25 by dbejar-s          #+#    #+#             */
/*   Updated: 2024/10/31 12:31:14 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3D.h"

void	load_game(void *param)
{
	t_macro	*in_game;

	in_game = param;	// cast to the mlx structure

}

void	load_player(t_macro *macro)
{
	macro->pos_pl_x = macro->play_x * BLOCK;
	macro->pos_pl_y = macro->play_y * BLOCK;
}

void 	load_map(char *file, t_macro *macro)
{
	int rows, cols;
	
	macro->map = parse_map(file, &rows, &cols);
	macro->floor = ft_pixel(100, 50, 150, 255);
	macro->ceiling = ft_pixel(0, 50, 50, 255);
	macro->play_x = 8;
	macro->play_y = 3;
}

int main(int argc, char** argv)
{
	t_macro	*macro;
	mlx_t	*first;
	
	if (argc != 2)
	{
		write(2, "To load the game: ./cub3D map.cub\n", 34);
		return(1);
	}
	macro = (t_macro *)ft_calloc(1, sizeof(t_macro));
	load_map(argv[1], macro);
	first = mlx_init(1, 1, "get_size", 0);
	mlx_get_monitor_size(0, &macro->width, &macro->height);
	printf("width %d height %d \n", macro->width, macro->height);
	mlx_terminate(first);
	macro->mlx_cub = mlx_init(macro->width * RATIO_SCREEN, macro->height * RATIO_SCREEN, "cub3D", 0);
	printf("\nAQUI EL MAPA\n\n");
	int i,j;
	i = 0;
	j = 0;
	while (macro->map[i] != NULL)
	{
		j = 0;
		while(macro->map[i][j])
		{
			if (j == macro->play_x && i == macro->play_y)
				printf("P");
			else
				printf("%c", macro->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	load_player(macro);
	mlx_loop_hook(macro->mlx_cub, &load_game, &macro->mlx_cub);
	mlx_key_hook(macro->mlx_cub, &ft_hook, &macro);
	mlx_loop(macro->mlx_cub);
	mlx_terminate(macro->mlx_cub);
	return (0);
}