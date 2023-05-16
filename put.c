/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:18:41 by kristori          #+#    #+#             */
/*   Updated: 2023/05/16 11:01:38 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

static int	ft_check_input_value(t_program *prog, int column)
{
	if (column >= prog->width)
		return (0);
	else if (column < 0)
		return (0);
	return (1);
}

static int	ft_check_column_full(t_program *prog, int column)
{
	for (int i = 0; i < prog->height; i++)
	{
		if (prog->matrix[i][column] == 0)
			return (0);
	}
	return (1);
}

int	ft_put(t_program *prog, int column)
{
	//check input value
	if (!ft_check_input_value(prog, column))
	{
		ft_printf("Invalid column, retry\n");
		return (0);
	}
	//check colonna piena
	if (!ft_check_column_full(prog, column))
	{
		if (is_playable(*prog, column))
			prog->matrix[get_height(*prog, column)][column] = 1;
	}
	else
		ft_printf("Colonna piena\n");
	return (1);
}
