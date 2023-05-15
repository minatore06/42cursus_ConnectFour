/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:36:48 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/15 15:44:44 by ncortigi         ###   ########.fr       */
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

int	check_input(int ac, char **av);
void	take_input(t_program *data, int ac, char **av);

#endif