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
	static int	reset = 0;
	t_program p2;

	if (played_moves(p) == p.height * p.width)
		return (0);
	if (reset)
	{
		for(int i = 0; i < p.width; i++)
        	order[i] = p.width / 2 + (1 - 2 * (i % 2)) * (i + 1) / 2;
		reset = 0;
	}
	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && is_winning_move(p, m, player))
		{
			*move = m;
			//ft_printf("Qualcuno vincera'%d | %d\n",(p.width * p.height + 1 - played_moves(p)) / 2, m);
			return ((p.width * p.height + 1 - played_moves(p)) / 2 );
		}
	}
	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && is_winning_move(p, m, change_player(player)))
		{
			*move = m;
			//ft_printf("Qualcun altro vincera'%d | %d\n",(p.width * p.height + 1 - played_moves(p)) / 2, m);
			return ((p.width * p.height + 1 - played_moves(p)) / 2 );
		}
	}
 	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, order[m]))
		{
			max = get_height(p, order[m]);
			p.matrix[max][order[m]] = player;
			tmp = order[m];
			if (is_playable(p, order[m]) && is_winning_move(p, order[m], change_player(player)))
			{
				//ft_printf("Non giocare questo %d\n",order[m]);
				reset = 1;
				order[m] = -1;
			}
			p.matrix[max][tmp] = 0;
		}
	}
	if (already_explored(brain, p, &score, move))
		return (score);
/*  	if (depth > 15)
		return ((p.width * p.height + 1 - played_moves(p)) / 2 ); */
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
		if (order[i] == -1)
			continue ;
		if (is_playable(p, order[i]))
		{
			p2 = p_copy(p);
			p2.matrix[get_height(p2, order[i])][order[i]] = player;
			player = change_player(player);
			score = -get_best_score(p2, player, &tmp, -beta, -alpha, depth + 1, order, brain);
			//ft_printf("Calcolo incredibile%d\n",score);
			if (score >= beta)
			{
				*move = i;
				return (score);
			}
			if (score > alpha)
			{
				*move = i;
				alpha = score;
			}
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
	add_brain_front(&brain, make_brain(p, *move, alpha, brain->id), p.height);
	return (alpha);
}

int	epic_solver(t_program p, int player, t_remember brain)
{
	int			order[p.width];
	int			min, max;
	int			med;
	int			score;
	int			move;

	for(int i = 0; i < p.width; i++)
        order[i] = p.width / 2 + (1 - 2 * (i % 2)) * (i + 1) / 2;
	min = -(p.width * p.height - played_moves(p)) / 2;
	max = (p.width * p.height + 1 - played_moves(p)) / 2;
	while (min < max)
	{
		med = min + (max - min) / 2;
		if (med <= 0 && min / 2 < med)
			med = min / 2;
		else if (med >= 0 && max / 2 > med)
			med = max / 2;
    	score = get_best_score(p, player, &move, med, med + 1, 0, order, &brain);
		if (score <= med)
			max = score;
		else
			min = score;
	}
	return (move);
}

void	easy_put(t_program p, int player)
{
	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && is_winning_move(p, m, player))
		{
			ai_play_move(p, m);
			return ;
		}
	}
	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && is_winning_move(p, m, change_player(player)))
		{
			ai_play_move(p, m);
			return ;
		}
	}
	if (is_playable(p, p.width / 2))
		ai_play_move(p, p.width / 2);
	else if (is_playable(p, p.width / 2 - 1))
		ai_play_move(p, p.width / 2 - 1);
}

void    ai_plays(t_program p, int player, t_remember brain)
{
	int			move;

	if (played_moves(p) / 2 < 2)
		easy_put(p, player);
	else
	{
		move = epic_solver(p, player, brain);
		ai_play_move(p, move);
	}
}