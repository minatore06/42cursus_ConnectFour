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

int **dup_matrix(t_program p)
{
    int     i;
	int     j;
    int    **maty;

    maty = malloc((p.height) * sizeof(int *));
    i = 0;
    while(i < p.height)
    {
		maty[i] = malloc(p.width * sizeof(int));
		j = 0;
        while (j < p.width)
        {
		    maty[i][j] = p.matrix[i][j];
            j++;
        }
        i++;
    }
	return (maty);
}

void	add_brain_front(t_remember **lst, t_remember *new)
{
	new->next = *lst;
	*lst = new;
}

t_remember	*make_brain(t_program p, int m, int score)
{
	t_remember	*node;

	node = malloc(sizeof(t_remember));
	if (node)
	{
        node->matrix = dup_matrix(p);
        node->move = m;
        node->score = score;
	    node->next = NULL;
	}
	return (node);
}

int mat_cmp(t_program p, int **maty)
{
    for (int i = 0; i < p.height; i++)
    {
        for (int j = 0; j < p.width; j++)
        {
            if (p.matrix[i][j] != maty[i][j])
                return (1);
        }
    }
    return (0);
}

int already_explored(t_remember *brain, t_program p, int *score)
{
    while (brain)
    {
        if (!mat_cmp(p, brain->matrix))
        {
            *score = brain->score;
            return (1);
        }
        brain = brain->next;
    }
    return (0);
}