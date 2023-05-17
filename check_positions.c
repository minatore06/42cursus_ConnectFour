/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:38:46 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/05/16 17:21:49 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int get_height(t_program p, int m)
{
    int i;

    for (i = p.height - 1; i >= 0; i--)
    {
        if (p.matrix[i][m] == 0)
            return (i);
    }
    return (-1);
}

int	is_playable(t_program p, int m)
{
	int	i;

	i = get_height(p, m);
	if (i >= 0 && !p.matrix[i][m])
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
	int	i, j;
	int	count;

	count = 1;
	i = get_height(p, m) + mod_i;
	j = m + mod_j;
	while ((i < p.height && i >= 0) && (j < p.width && j >= 0))
	{
		if (p.matrix[i][j] != player)
			return (count);
		count++;
		if (count == 4)
			return (count);
		i += mod_i;
		j += mod_j;
	}
	return (count);
}

int is_winning_move(t_program p, int m, int player)
{
    int i, j;
	int	is_win;

    i = get_height(p, m);
    j = m;
	if (check_one_dir(p, m, player, -1, 0) + check_one_dir(p, m, player, 1, 0) >= 4 ||
		check_one_dir(p, m, player, -1, 1) + check_one_dir(p, m, player, 1, -1) >= 4 ||
		check_one_dir(p, m, player, 0, 1) + check_one_dir(p, m, player, 0, -1) >= 4 ||
		check_one_dir(p, m, player, 1, 1) + check_one_dir(p, m, player, -1, -1) >= 4)
		return (1);
    return (0);
}
