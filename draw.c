/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:09:36 by javellis          #+#    #+#             */
/*   Updated: 2023/05/17 17:31:56 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static void mlx_fill_square(t_program *prog, int x, int y, int size, int color)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ft_mlx_pixel_put(prog, x + i, y + j, color);
		}
	}
}

int ft_draw(t_program *prog)
{
    // mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
    for(int i = 0; i < prog->height; i++)
    {
        for(int j = 0; j < prog->width; j++)
        {
            mlx_fill_square(prog, i * 64, j * 64, 64, create_trgb(0, 0, 20, 203));
        }
    }
    return 0;
}

void    ft_draw_grid(t_program *prog)
{
    for(int i = 0; i < prog->height; i++)
    {
        for(int j = 0; j < prog->width + 1; j++)
        {
            if(prog->matrix[i][j] == 0)
                mlx_put_image_to_window(prog->mlx, prog->window, prog->empthy.reference, j * 64, (i+1) *64);
            else if(prog->matrix[i][j] == 1)
                mlx_put_image_to_window(prog->mlx, prog->window, prog->player_img.reference, j * 64, (i+1) *64);
            else if(prog->matrix[i][j] == 2)
                mlx_put_image_to_window(prog->mlx, prog->window, prog->cpu.reference, j * 64, (i+1) *64);
            else if(prog->matrix[i][j] == 3)
                mlx_put_image_to_window(prog->mlx, prog->window, prog->player_win.reference, j * 64, (i+1) *64);
            else if(prog->matrix[i][j] == 4)
                mlx_put_image_to_window(prog->mlx, prog->window, prog->cpu_win.reference, j * 64, (i+1) *64);
        }
    }
}
