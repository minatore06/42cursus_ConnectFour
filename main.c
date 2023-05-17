/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:49:29 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/17 10:11:40 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	main(int argc, char **argv)
{
	t_program	data;
	char		*input;
	int			column;

	if (!check_input(argc, argv))
		return (0);
	take_input(&data, argv, argc);
	if (data.gui > 0)
	{
		ft_gui_init(&data);
		mlx_mouse_hook(data.window, ft_input, &data);
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
				ft_put(&data, column - 1);
				ai_plays(data, data.player);
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
