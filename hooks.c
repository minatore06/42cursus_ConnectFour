/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:41:35 by javellis          #+#    #+#             */
/*   Updated: 2023/05/18 11:23:49 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"connect4.h"

int ft_input(int button, int x, int y, t_program *param)
{
    (void)y;
    if (button == 1)
    {
        t_program *prog = (t_program *)param;
        if (ft_put(prog, x / 64))
        {
            mlx_clear_window(prog->mlx, prog->window);
            ft_draw_grid(prog);
            ft_printf("\e[1;1H\e[2J");
            ft_draw_grid_terminal(prog);
            if(check_win(*prog, x / 64, 1) == 1)
            {
                ft_printf("\e[1;1H\e[2J");
                ft_draw_grid_terminal(prog);
                ft_draw_win_terminal();
                return (0);
            }
            if(check_draw(*prog, x / 64, 1))
            {
                ft_draw_grid_terminal(prog);
                ft_draw_draw_terminal();
                return (0);
            }
            prog->turn++;
            int ai_move = ai_plays(*prog, prog->player, *(prog->remember));
			ft_printf("\e[1;1H\e[2J");
            ft_draw_grid_terminal(prog);
            if(check_win(*prog, ai_move, 2) == 2)
            {
                ft_printf("\e[1;1H\e[2J");
                ft_draw_grid_terminal(prog);
                ft_draw_lose_terminal();
                return (0);
            }
            if(check_draw(*prog, ai_move, 2))
            {
                ft_draw_grid_terminal(prog);
                ft_draw_draw_terminal();
                return (0);
            }
            prog->turn++;
        }
    }
    return 1;
}

int ft_mouse_move(int x, int y, void *param)
{
    (void)y;
    t_program *prog = (t_program *)param;
    mlx_clear_window(prog->mlx, prog->window);
    ft_draw_grid(prog);
    mlx_put_image_to_window(prog->mlx, prog->window, prog->fiche.reference, x - 32, 0);
    return (1);
}
