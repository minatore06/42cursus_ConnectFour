/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:36:48 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/16 11:59:48 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include "libft/libft.h"
# include <stdlib.h>
# include <time.h>

typedef struct s_program
{
    int height;
    int width;
    int **matrix;
    int win;
    int turn;
    int player;
}   t_program;

void	    ft_draw_start_terminal(t_program *prog);
void	    ft_draw_grid_terminal(t_program *prog);
int			check_input(int ac, char **av);
void		take_input(t_program *data, char **av);
int	        ft_put(t_program *prog, int column);

int			is_playable(t_program p, int m);
int			is_winning_move(t_program p, int m, int player);
int			played_moves(t_program p);
int 		get_height(t_program p, int m);

t_program	p_copy(t_program p);
void		p_free(t_program p);
int	        ft_random_start(t_program *prog);

void		ai_plays(t_program p, int player);

int			check_win(t_program p, int m, int pl);
#endif
