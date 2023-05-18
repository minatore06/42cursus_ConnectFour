/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:49:29 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/17 18:06:04 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	main(int argc, char **argv)
{
	t_program	data;
	t_remember	brain;
	char		*input;
	int			column;

	if (!check_input(argc, argv))
		return (0);
	take_input(&data, argv, argc);
	if (data.gui > 0)
	{
		ft_random_start(&data);
		if (data.player == 2)
		{
			data.matrix[data.height - 1][data.width / 2] = 2;
		}
		brain.matrix = dup_matrix(data);
		brain.move = data.width / 2;
		brain.score = 0;
		brain.id = 0;
		brain.next = NULL;
		data.remember = &brain;
		ft_gui_init(&data);
	    ft_draw_grid(&data);
		mlx_mouse_hook(data.window, ft_input, &data);
		mlx_hook(data.window, 6 , (1L<<6), ft_mouse_move, &data);
		mlx_hook(data.window, 17, 0, ft_close, &data);
		mlx_loop(data.mlx);
	}
	else
	{
		ft_printf("\e[1;1H\e[2J");
		ft_draw_start_terminal(&data);
		if (get_next_line(0))
			ft_printf("\e[1;1H\e[2J");
		ft_random_start(&data);
		brain.matrix = dup_matrix(data);
		brain.move = data.width / 2;
		brain.score = 0;
		brain.id = 0;
		brain.next = NULL;
		if (data.player == 2)
		{
			data.matrix[data.height - 1][data.width / 2] = 2;
		}
		while (1)
		{
			ft_draw_grid_terminal(&data);
			ft_printf("Insert n of column: ");
			input = get_next_line(0);
			if (ft_check_input_string(input))
			{
				column = ft_atoi(input);
				ft_printf("\e[1;1H\e[2J");
				if (ft_put(&data, column - 1))
				{
					if(check_win(data, column - 1, 1) == 1)
					{
						ft_draw_grid_terminal(&data);
						ft_printf("hai vinto!\n");
						return (0);
					}
					int ai_move = ai_plays(data, data.player, brain);
					ft_printf("ai_move: %d\n", ai_move);
					if(check_win(data, ai_move, 2) == 2)
					{
						ft_draw_grid_terminal(&data);
						ft_printf("hai perso!\n");
						return (0);
					}
				}
			}
			else
			{
				ft_printf("\e[1;1H\e[2J");
				ft_printf("Invalid number, retry\n");
			}
		}
	}
	return (0);
}
