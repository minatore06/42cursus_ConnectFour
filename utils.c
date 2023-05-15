/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:09:41 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/05/15 17:09:56 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

t_program   p_copy(t_program p)
{
    t_program   p2;

    p2.height = p.height;
	p2.width = p.width;
	p2.matrix = ft_calloc(sizeof(int *), (p.height + 1));
	for (int i=0; i <= p.height; i++)
		p2.matrix[i] = ft_calloc(sizeof(int), (p.width + 1));
    for (int i=0; i < p.height; i++)
    {
        for (int j = 0; j < p.width; j++)
        {
		    p2.matrix[i][j] = p.matrix[i][j];
        }
    }
    return (p2);    
}

void    p_free(t_program p)
{
    for (int i = 0; i <= p.height; i++)
    {
        free(p.matrix[i]);
    }
    free(p.matrix);
}