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
			return (1);
	}
	return (0);
}

int	ft_put(t_program *prog, int column)
{
	//check input value
	if (ft_check_input_value(prog, column) == 0)
	{
		ft_printf("Invalid column, retry\n");
		return (0);
	}
	//check colonna piena
	if (ft_check_column_full(prog, column) == 1)
	{
		for (int i = 0; i < prog->height; i++)
		{
			if (prog->matrix[i + 1][column] != 0)
				prog->matrix[i][column] = 1;
			if (i == prog->height - 1 && prog->matrix[i][column] == 0)
				prog->matrix[i][column] = 1;
		}
	}
	else
		ft_printf("Colonna piena\n");
	return (1);
}
