/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:59:25 by dbejar-s          #+#    #+#             */
/*   Updated: 2024/10/31 07:30:18 by dbejar-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3D.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// 	image->instances[0].y -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// 	image->instances[0].y += 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// 	image->instances[0].x -= 5;
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// 	image->instances[0].x += 5;
}

char** parse_map(const char* filename, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    // Determine the number of rows and columns
    char buffer[256];
    *rows = 0;
    *cols = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        if (*cols == 0) {
            *cols = strlen(buffer) - 1; // Exclude newline character
        }
        (*rows)++;
    }

    // Allocate memory for the map
    char** map = (char**)malloc((*rows + 1) * sizeof(char*));
    if (!map) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    // Read the file again to fill the map
    rewind(file);
    for (int i = 0; i < *rows; i++) {
        map[i] = (char*)malloc((*cols + 1) * sizeof(char)); // +1 for null terminator
        if (!map[i]) {
            perror("Failed to allocate memory");
            fclose(file);
            return NULL;
        }
        fgets(map[i], *cols + 2, file); // +2 to include newline and null terminator
        map[i][*cols] = '\0'; // Remove newline character
    }
	map[*rows] = NULL;
    fclose(file);
    return map;
}


void load_map(char *file, t_macro *macro)
{
	int rows, cols;
	
	macro->map = parse_map(file, &rows, &cols);
	macro->floor = ft_pixel(100, 50, 150, 255);
	macro->ceiling = ft_pixel(0, 50, 50, 255);
	macro->play_x = 5;
	macro->play_y = 5;
}

int main(int argc, char** argv)
{
	t_macro	*macro;
	mlx_t	*first;
	int32_t	moni_w;
	int32_t	moni_h;
	
	if (argc != 2)
	{
		write(2, "To load the game: ./cub3D map.cub\n", 34);
		return(1);
	}
	macro = (t_macro *)ft_calloc(1, sizeof(t_macro));
	load_map(argv[1], macro);
	first = mlx_init(1, 1, "get_size", 0);
	mlx_get_monitor_size(0, &moni_w, &moni_h);
	printf("%d y %d son: \n", moni_w, moni_h);
	mlx_terminate(first);
	macro->mlx_cub = mlx_init(moni_w * 0.69, moni_h * 0.69, "cub3D", 0);
	printf("XXXXXXXXXXXXXXXXXXXX\n");
	int i,j;
	i = 0;
	j = 0;
	while (macro->map[i] != NULL)
	{
		j = 0;
		while(macro->map[i][j])
		{
			printf("%c", macro->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	mlx_loop_hook(macro->mlx_cub, ft_hook, &macro->mlx_cub);
	mlx_loop(macro->mlx_cub);
	mlx_terminate(macro->mlx_cub);
	return (0);
}