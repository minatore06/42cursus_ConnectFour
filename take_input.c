/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:45:03 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/16 18:00:54 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	check_input(int ac, char **av)
{
	int i;
	int j;
	int	ret;

	j = 1;
	ret = 1;
	if (ac > 4 || ac < 3)
	{
		ft_printf("Error: invalid arguments\nUse: ./connect4 [number_of_lines][number_of_columns]{-gui}\n");
		return (0);
	}
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (j == 3)
			{
				if (ft_strncmp(av[3], "-gui", 4))
				{
					ft_printf("Error: -gui\n");
					return (0);
				}
			}
			else if (av[j][i] < '0' || av[j][i] > '9')
				ret = 0;
			i++;
		}
		j++;
	}
	if (ret != 1)
	{
		ft_printf("Error: invalid argument\n");
		return (0);
	}
	if (ft_atoi(av[1]) < 6 || ft_atoi(av[2]) < 7)
	{
		ft_printf("Error: Invalid size\n");
		return (0);
	}
	else if (ft_atoi(av[1]) > 50 || ft_atoi(av[2]) > 42)
	{
		ft_printf("Grid: too large for the terminal, try 50x42 max\n");
		return (0);
	}
	return (1);
}

void	take_input(t_program *data, char **av, int ac)
{
	data->height = ft_atoi(av[1]);
	data->width = ft_atoi(av[2]);
	data->gui = 0;
	if (ac == 4)
	{
		if (!ft_strncmp(av[3], "-gui", 4))
			data->gui = 1;
	}
	data->matrix = ft_calloc(sizeof(int *), (data->height + 1));
	for (int i=0; i <= data->height; i++)
		data->matrix[i] = ft_calloc(sizeof(int), (data->width +1));
}
