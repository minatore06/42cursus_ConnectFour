/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:30:38 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/05/15 16:30:40 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	get_best_score(t_program p, int player)
{
	int	bestScore;
	int	score;
	t_program p2;
	//check draw

	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && is_winning_move(p, m, player))
			return ((p.width * p.height + 1 - played_moves(p)) / 2 );
	}
	bestScore = -p.height * p.width;
	for (int i = 0; i < p.width; i++)
	{
		if (player == 1)
			player = 2;
		else
			player = 1;
		p2 = p_copy(p);
		p2.matrix[i][get_height(p2, i)] = player;
		score = -get_best_score(p2, player);
		if (score > bestScore) bestScore = score;
		p_free(p2);
	}
	return (bestScore);
}

void    ai_plays(t_program p, int player)
{
    get_best_score(p, player);
}