/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:41:35 by javellis          #+#    #+#             */
/*   Updated: 2023/05/17 15:25:49 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"connect4.h"

int ft_input(int button, int x, int y, t_program *param)
{
    if (button == 1)
    {
        t_program *prog = (t_program *)param;
        if (ft_put(prog, x / 64))
        {
            mlx_clear_window(prog->mlx, prog->window);
            ft_draw_grid(prog);
            ft_printf("\e[1;1H\e[2J");
            ft_draw_grid_terminal(prog);
            // if(check_win(*prog, x / 64, prog->player) == prog->player)
            // {
            //     printf("hai vinto!\n");
            //     return 0;
            // }
            // ai_plays(*prog, prog->player);
        }
        // ft_draw(prog);
        // mlx_put_image_to_window(prog->mlx, prog->window, prog->buffer.reference, 0, 0);
    }
    return 1;
}

int ft_mouse_move(int x, int y, void *param)
{
    t_program *prog = (t_program *)param;
    mlx_clear_window(prog->mlx, prog->window);
    ft_draw_grid(prog);
    mlx_put_image_to_window(prog->mlx, prog->window, prog->fiche.reference, x - 32, 0);
}