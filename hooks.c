/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:41:35 by javellis          #+#    #+#             */
/*   Updated: 2023/05/17 10:02:34 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"connect4.h"
#include<stdio.h>

int ft_input(int button, int x, int y, t_program *param)
{
    (void)param;
    t_program *prog = (t_program *)param;
    printf("x = %d, y = %d, button = %d\n", x, y, button);
    // ft_draw(prog);
    // mlx_put_image_to_window(prog->mlx, prog->window, prog->buffer.reference, 0, 0);
    ft_draw_grid(prog);
	ft_printf("\e[1;1H\e[2J");
	ft_draw_grid_terminal(prog);
    return 1;
}
