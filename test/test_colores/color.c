#include "../../include/MLX42.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BPP sizeof(int32_t) //Bytes Per Pixel

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}


int32_t	main(void)
{
 
    mlx_t* mlx = mlx_init(512, 512, "Motherfoca", false);
    
    if (!mlx)
        exit(EXIT_FAILURE);
    mlx_image_t* img = mlx_new_image(mlx, 512, 512);
    mlx_image_to_window(mlx, img, 0, 0);

    int i, j;
    uint32_t wall, lines, left, right, roof, floor;

    wall = (uint32_t)get_rgba(200, 21, 111, 255);
    lines = (uint32_t)get_rgba(0, 0, 0, 255);
    left = (uint32_t)get_rgba(0, 255, 255, 255);
    right = (uint32_t)get_rgba(255, 0, 255, 255);
    roof = (uint32_t)get_rgba(255, 255, 0, 255);
    floor = (uint32_t)get_rgba(20, 60, 100, 255);
    // mlx_put_pixel(img, 0, 0, micolor);

    i = 0;
    j = 0;

    while (i < 512)
    {
        j = 0;
        while (j < 256)
        {
            mlx_put_pixel(img, i, j, roof);   
            j++;
        }
        i++;
    }

    i = 0;
    j = 256;

    while (i < 512)
    {
        j = 256;
        while (j < 512)
        {
            mlx_put_pixel(img, i, j, floor);   
            j++;
        }
        i++;
    }

    i = 0;
    j = 0;

    while (i < 256)
    {
        j = 0;
        while (j < 256)
        {
            if (i <= j)
                mlx_put_pixel(img, i, j, left);   
            j++;
        }
        i++;
    }
    i = 0;
    while (i < 256)
    {
        j = 511;
        while (j > 255)
        {
            if (i <= 511 - j)
                mlx_put_pixel(img, i, j, left); 
            j--;
        }
        i++;
    }

    i = 511;
    j = 0;

    while (i > 255)
    {
        j = 0;
        while (j < 255)
        {
            if (i >= 511 - j)
                mlx_put_pixel(img, i, j, right);             
            j++;
        }
        i--;
    }

    i = 511;
    j = 511;
    while (i >= 255)
    {
        j = 511;
        while (j >= 255)
        {
            if (i >= j)
                mlx_put_pixel(img, i, j, right);             
            j--;
        }
        i--;
    }  

    i = 0;

    while (i < 512)
    {
        mlx_put_pixel(img, i, i, lines);
        i++;

    }   
   
    j = 511;
    while (j >= 0)
    {
        mlx_put_pixel(img, 511-j, j, lines);
        j--;

    }   

    i = 128;
    j = 128;  

    while (i < 384)
    {
        j = 128;
        while (j < 384)
        {
            mlx_put_pixel(img, i, j, wall);
            j++;
        }
        i++;
        //printf("\nnueva linea %d\n", i);
    }

   	mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (0);
}
