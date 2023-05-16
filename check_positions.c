/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:38:46 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/05/16 11:28:55 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int get_height(t_program p, int m)
{
    int i;

    for (i = p.height - 1; i >= 0; i--)
    {
        if (p.matrix[i][m] == 0)
            break;
    }
    return (i);
}

int	is_playable(t_program p, int m)
{
	int	i;

	i = get_height(p, m);
	if (!p.matrix[i][m])
		return (1);
	return (0);
}

int	played_moves(t_program p)
{
	int	count;

	count = 0;
	for (int i = 0; i < p.height; i++)
	{
		for (int j = 0; j < p.width; j++)
		{
			if (p.matrix[i][j])
				count++;
		}
	}
	return (count);
}

int	check_one_dir(t_program p, int m, int player, int mod_i, int mod_j)
{
	int	count;

	count = 1;
	for (int i = get_height(p, m) + mod_i; i < p.height && i >= 0; i+=mod_i)
	{
		for (int j = m + mod_j; j < p.width && j >= 0; j+=mod_j)
		{
			if (p.matrix[i][j] != player)
				return (0);
			count++;
			if (count == 4)
				break;
		}
	}
	return (1);
}

int is_winning_move(t_program p, int m, int player)
{
    int i, j;

    i = get_height(p, m);
    j = m;
	if (check_one_dir(p, m, player, -1, 0) ||
		check_one_dir(p, m, player, -1, 1) ||
		check_one_dir(p, m, player, 0, 1) ||
		check_one_dir(p, m, player, 1, 1) ||
		check_one_dir(p, m, player, 1, 0) ||
		check_one_dir(p, m, player, 1, -1) ||
		check_one_dir(p, m, player, 0, -1) ||
		check_one_dir(p, m, player, -1, -1))
		return (1);
    return (0);
}
