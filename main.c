/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:49:29 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/16 12:29:42 by kristori         ###   ########.fr       */
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
	take_input(&data, argv);
	ft_printf("\e[1;1H\e[2J");
	ft_draw_start_terminal(&data);
	if (get_next_line(0))
		ft_printf("\e[1;1H\e[2J");
	ft_random_start(&data);
	if (data.player == 2)
	{
		data.matrix[5][2] = 2;
	}
	while (data.win != 1)
	{
		ft_draw_grid_terminal(&data);
		ft_printf("Insert n of column: ");
		input = get_next_line(0);
		column = ft_atoi(input);
		ft_printf("\e[1;1H\e[2J");
		ft_put(&data, column - 1);
		free(input);
	}
	return (0);
}
