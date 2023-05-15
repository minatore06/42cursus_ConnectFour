/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:36:48 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/15 15:56:01 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H
# include "libft/libft.h"

typedef struct s_program
{
    int height;
    int width;
    int **matrix;
    int win;
}   t_program;

int			check_input(int ac, char **av);
void		take_input(t_program *data, char **av);

int			is_playable(t_program p, int m);
int			is_winning_move(t_program p, int m, int player);
int			played_moves(t_program p);
int 		get_height(t_program p, int m);

t_program	p_copy(t_program p);
void		p_free(t_program p);

#endif