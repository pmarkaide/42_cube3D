/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:59:25 by dbejar-s          #+#    #+#             */
/*   Updated: 2024/11/01 23:34:38 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void load_game(t_macro *macro)
{
    mlx_delete_image(macro->mlx_cub, macro->img);
    macro->img = mlx_new_image(macro->mlx_cub, macro->width, macro->height);
    paint_background(macro);
    paint_wall(macro);
    mlx_image_to_window(macro->mlx_cub, macro->img, 0, 0);
}

void load_player(t_macro *macro)
{
    macro->pos_pl_x = macro->start_x * BLOCK + BLOCK / 2;
    macro->pos_pl_y = macro->start_y * BLOCK + BLOCK / 2;
    macro->play_view = M_PI * ANGLE_VIEW / 180;
    if (macro->orientation == 'N')
        macro->play_angle = 3 * M_PI / 2;
    else if (macro->orientation == 'E')
        macro->play_angle = 0;
    else if (macro->orientation == 'S')
        macro->play_angle = M_PI / 2;
    else if (macro->orientation == 'W')
        macro->play_angle = M_PI;
}

void load_map(char *file, t_macro *macro)
{
    int rows, cols;
    macro->map = parse_map(file, &rows, &cols);
    macro->floor = ft_pixel(0, 255, 128, 255);
    macro->ceiling = ft_pixel(135, 206, 235, 255);
    macro->start_x = 10;
    macro->start_y = 7;
    macro->orientation = 'E';
}

int main(int argc, char **argv)
{
    t_macro *macro;
    mlx_t *first;

    if (argc != 2)
    {
        write(2, "To load the game: ./cub3D map.cub\n", 34);
        return (1);
    }
    macro = (t_macro *)ft_calloc(1, sizeof(t_macro));
    if (!macro)
    {
        perror("Failed to allocate memory for macro");
        return 1;
    }
    load_map(argv[1], macro);
    first = mlx_init(800, 600, "Loading...", 0);
    mlx_get_monitor_size(0, &macro->width, &macro->height);
    printf("width %d height %d \n", macro->width, macro->height);
    mlx_terminate(first);
    macro->width *= RATIO_SCREEN;
    macro->height *= RATIO_SCREEN;
    macro->mlx_cub = mlx_init(macro->width, macro->height, "cub3D", 0);
    printf("\nAQUI EL MAPA\n\n");
    print_map(macro);
    load_player(macro);
    load_game(macro);
    mlx_key_hook(macro->mlx_cub, &ft_hook, macro);
    mlx_loop(macro->mlx_cub);
    mlx_terminate(macro->mlx_cub);
    return (0);
}
