/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:45:01 by kristori          #+#    #+#             */
/*   Updated: 2023/05/17 17:41:46 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	ft_draw_grid_terminal(t_program *prog)
{
	int	i;
	int	j;

	for (i = 0; i < prog->width; i++)
		ft_printf("=====");
	ft_printf("\n");
	for (i = 0; i < prog->height; i++)
	{
		for (j = 0; j < prog->width; j++)
		{
			if (prog->matrix[i][j] == 0)
				ft_printf("|   |", prog->matrix[i][j]);
			else if (prog->matrix[i][j] == 1)
			{
				ft_printf("| ");
				ft_printf("\033[1;31m");
				ft_printf("●", prog->matrix[i][j]);
				ft_printf("\033[0m");
				ft_printf(" |");
			}
			else if (prog->matrix[i][j] == 2)
			{
				ft_printf("| ");
				ft_printf("\033[1;33m");
				ft_printf("●", prog->matrix[i][j]);
				ft_printf("\033[0m");
				ft_printf(" |");
			}
			else if (prog->matrix[i][j] == 3)
			{
				ft_printf("| ");
				ft_printf("\033[1;31m");
				ft_printf("✘", prog->matrix[i][j]);
				ft_printf("\033[0m");
				ft_printf(" |");
			}
			else if (prog->matrix[i][j] == 4)
			{
				ft_printf("| ");
				ft_printf("\033[1;33m");
				ft_printf("✘", prog->matrix[i][j]);
				ft_printf("\033[0m");
				ft_printf(" |");
			}
		}
		ft_printf("\n");
	}
	for (i = 0; i < prog->width; i++)
		ft_printf("=====");
	ft_printf("\n");
	for (i = 1; i < prog->width + 1; i++)
	{
		if (i >= 10 && i <= 99)
			ft_printf("|%d |", i);
		else
			ft_printf("| %d |", i);
	}
	ft_printf("\n");
}

void	ft_draw_start_terminal(t_program *prog)
{
	ft_printf(" ██████  ██████  ███    ██ ███    ██ ███████  ██████ ████████ ██   ██\n"
				"██      ██    ██ ████   ██ ████   ██ ██      ██         ██    ██   ██\n"
				"██      ██    ██ ██ ██  ██ ██ ██  ██ █████   ██         ██    ███████\n"
				"██      ██    ██ ██  ██ ██ ██  ██ ██ ██      ██         ██         ██\n"
				" ██████  ██████  ██   ████ ██   ████ ███████  ██████    ██         ██\n");
	ft_printf("\n");
	ft_printf("	Your grid is %dx%d\n", prog->height, prog->width);
	ft_printf("\033[1;33m");
	ft_printf("\e[5m	Press Enter to start\e[m\n");
	ft_printf("\033[0m");
}
