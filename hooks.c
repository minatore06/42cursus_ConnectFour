/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:41:35 by javellis          #+#    #+#             */
/*   Updated: 2023/05/18 16:04:39 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"connect4.h"

int ft_input(int button, int x, int y, t_program *param)
{
    (void)y;
    char *tmp;
    t_program *prog = (t_program *)param;
    if (button == 1 && prog->win == 0)
    {
        if (ft_put(prog, x / 64))
        {
            tmp = ft_strjoin("Turn : ", ft_itoa(prog->turn));
            mlx_clear_window(prog->mlx, prog->window);
            ft_draw_grid(prog);
            mlx_string_put(prog->mlx, prog->window, 20, ((prog->height + 1) *  64) + 12, create_trgb(0,255,255,255), tmp);
            ft_printf("\e[1;1H\e[2J");
            ft_draw_grid_terminal(prog);
            if(check_win(*prog, x / 64, 1) == 1)
            {
                ft_printf("\e[1;1H\e[2J");
                ft_draw_grid_terminal(prog);
                ft_draw_win_terminal();
                prog->win = 1;
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
            mlx_string_put(prog->mlx, prog->window, 150, ((prog->height + 1) *  64) + 12, create_trgb(0,255,255,255), "Opponent is playing...");
            mlx_string_put(prog->mlx, prog->window, 20, ((prog->height + 1) *  64) + 12, create_trgb(0,255,255,255), tmp);
			ft_printf("\e[1;1H\e[2J");
            ft_draw_grid_terminal(prog);
            if(check_win(*prog, ai_move, 2) == 2)
            {
                ft_printf("\e[1;1H\e[2J");
                ft_draw_grid_terminal(prog);
                ft_draw_lose_terminal();
                prog->win = 2;
                return (0);
            }
            free(tmp);
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
    char *tmp = ft_strjoin("Turn : ", ft_itoa(prog->turn));
    mlx_clear_window(prog->mlx, prog->window);
    ft_draw_grid(prog);
    mlx_string_put(prog->mlx, prog->window, 20, ((prog->height + 1) *  64) + 12, create_trgb(0,255,255,255), tmp);
    mlx_put_image_to_window(prog->mlx, prog->window, prog->fiche.reference, x - 32, 0);
    free(tmp);
    return (1);
}

int ft_esc(int keycode, void *param)
{
    if(keycode == 65307)
        ft_close(param);
    return 0;
}