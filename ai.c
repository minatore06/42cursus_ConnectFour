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

int	change_player(int player)
{
	if (player == 1)
		return (2);
	else if (player == 2)
		return (1);
	return (42);
}

void	ai_play_move(t_program p, int m)
{
	if (is_playable(p, m))
	{
		p.matrix[get_height(p, m)][m] = 2;
	}
}

int	get_best_score(t_program p, int player, int *move, int alpha, int beta, int depth, int order[], t_remember *brain)
{
	int	max;
	int	score;
	int	tmp;
	t_program p2;
	
	if (played_moves(p) == p.height * p.width)
		return (0);

	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && is_winning_move(p, m, player))
		{
			*move = m;
			//ft_printf("Qualcuno vincera'%d | %d\n",(p.width * p.height + 1 - played_moves(p)) / 2, m);
			return ((p.width * p.height + 1 - played_moves(p)) / 2 );
		}
	}
	if (depth > 20)
		return (0); 
	max = (p.width * p.height - 1 - played_moves(p)) / 2;
	if (beta > max)
	{
		beta = max;
		if (alpha >= beta)
			return (beta);
	}
	//ft_printf("sos%d\n",depth);
	for (int i = 0; i < p.width; i++)
	{
		if (is_playable(p, order[i]))
		{
			p2 = p_copy(p);
			p2.matrix[get_height(p2, order[i])][order[i]] = player;
			player = change_player(player);
			if (!already_explored(brain, p2, &score))
			{
				score = -get_best_score(p2, player, &tmp, -beta, -alpha, depth + 1, order, brain);
				//ft_printf("Calcolo incredibile%d\n",score);
				add_brain_front(&brain, make_brain(p2, i, score));
			}
			if (score >= beta)
				return (score);
			if (score > alpha)
				alpha = score;
/* 			if (score > bestScore)
			{
				//ft_printf("Cambiamento nell'universo%d | %d\n",score, i);
				*move = i;
				bestScore = score;
			} */
			p_free(p2);
			player = change_player(player);
		}
	}
	return (alpha);
}

void    ai_plays(t_program p, int player)
{
	int			move;
	int			order[p.width];
	t_remember	brain;

	brain.matrix = dup_matrix(p);
	brain.move = p.width / 2;
	brain.score = 0;
	brain.next = NULL;
	for(int i = 0; i < p.width; i++)
        order[i] = p.width / 2 + (1 - 2 * (i % 2)) * (i + 1) / 2;
    get_best_score(p, player, &move, -3, 3, 0, order, &brain);
	ai_play_move(p, move);
}