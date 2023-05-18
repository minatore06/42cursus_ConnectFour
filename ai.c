/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:30:38 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/05/17 17:43:52 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void	ai_play_move(t_program p, int m)
{
	if (is_playable(p, m))
	{
		p.matrix[get_height(p, m)][m] = 2;
	}
}

int	get_best_score(t_program p, int player, int *move, int alpha, int beta, int depth, t_remember *brain)
{
	int	max, min;
	int	score;
	int	tmp;
	int order[p.width];
	t_program p2;

	if (played_moves(p) == p.height * p.width)
		return (0);
	for(int i = 0; i < p.width; i++)
		order[i] = p.width / 2 + (1 - 2 * (i % 2)) * (i + 1) / 2;
	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && check_win_ai(p, m, player, 0) > 0)
		{
			*move = m;
			//ft_printf("Qualcuno vincera'%d | %d\n",(p.width * p.height + 1 - played_moves(p)) / 2, m);
			return ((p.width * p.height + 1 - played_moves(p)) / 2 );
		}
	}
	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && check_win_ai(p, m, change_player(player), 0) > 0)
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
/* 			for (int i = 0; i < p.height; i++)
			{
				ft_printf("cacca");
				for (int j = 0; j < p.width; j++)
				{
					ft_printf("%d", p.matrix[i][j]);
				}
				ft_printf("\n");
			}
			exit(3); */
			tmp = order[m];
			if (is_playable(p, order[m]) && check_win_ai(p, order[m], change_player(player), 0) > 0)
			{
				//ft_printf("Non giocare questo %d\n",order[m]);
				order[m] = -1;
			}
			p.matrix[max][tmp] = 0;
		}
	}
	if (depth > 12)
		return (0);
	min = -(p.width * p.height - 1 - played_moves(p)) / 2;
	if (alpha < min)
	{
		alpha = min;
		if (alpha >= beta)
			return (alpha);
	}
	max = (p.width * p.height - 1 - played_moves(p)) / 2;
	if (already_explored(brain, p, &score, move))
	{
		max = score;
	}
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
			score = -get_best_score(p2, player, &tmp, -beta, -alpha, depth + 1, brain);
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
	int			min, max;
	int			med;
	int			bestScore;
	int			score;
	int			move;
	int			tmp;

	move = -1;
	min = -(p.width * p.height - played_moves(p)) / 2;
	max = (p.width * p.height + 1 - played_moves(p)) / 2;
	bestScore = min;
	while (min < max)
	{
		med = min + (max - min) / 2;
		if (med <= 0 && min / 2 < med)
			med = min / 2;
		else if (med >= 0 && max / 2 > med)
			med = max / 2;
    	score = get_best_score(p, player, &tmp, med, med + 1, 0, &brain);
		ft_printf("score %d, move %d\n", score, tmp);
		if (score > bestScore)
		{
			bestScore = score;
			move = tmp;
		}
		if (score <= med)
			max = score;
		else
			min = score;
	}
	return (move);
}

int	easy_put(t_program p, int player)
{
	int	x;

	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && check_win_ai(p, m, player, 0) > 0)
		{
			ai_play_move(p, m);
			return (m);
		}
	}
	for (int m = 0; m < p.width; m++)
	{
		if (is_playable(p, m) && check_win_ai(p, m, change_player(player), 0) > 0)
		{
			ai_play_move(p, m);
			return (m);
		}
	}
	if (played_moves(p) / 2 < 1 && is_playable(p, p.width / 2))
	{
		ai_play_move(p, p.width / 2);
		return (p.width / 2);
	}
	else
	{
		x = destroy_enemy(p, player);
		if (x >= 0)
			ai_play_move(p, x);
		else
		{
			x = p.width / 2;
			ai_play_move(p, x);
		}
		return (x);
	}
	return (-1);
}

int    ai_plays(t_program p, int player, t_remember brain)
{
	int			move;

	if (played_moves(p) / 2 < 3)
		move = easy_put(p, player);
	else
	{
		move = epic_solver(p, player, brain);
		ai_play_move(p, move);
	}
	return (move);
}
