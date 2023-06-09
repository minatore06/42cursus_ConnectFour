/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:09:41 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/05/18 15:52:37 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int ft_check_input_string(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

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

int	ft_close(void *param)
{
	t_program	*program;

	program = (t_program *)param;
	ft_free_all(program);
	exit(0);
}

void	ft_free_all(t_program *program)
{
	mlx_destroy_window(program->mlx, program->window);
	mlx_destroy_display(program->mlx);
	free(program->mlx);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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

void	free_matrix(int **mat, t_program *data, int k)
{
    int     i;

    if (!mat)
        return ;
    i = 0;
    if (k == 1)
    {
        while(i < data->height)
        {
            free(mat[i]);
            i++;
        }
    }
    if (k == 2)
    {
        while(i <= data->height)
        {
            free(mat[i]);
            i++;
        }
    }
	free(mat);
}

t_remember  *last_brain(t_remember *lst)
{
    if (!lst)
        return (lst);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void    free_cell(t_remember *cell, int height)
{
    for (int i = 0; i <= height; i++)
    {
        free(cell->matrix[i]);
    }
    free(cell->matrix);
    free(cell);
}

void	add_brain_front(t_remember **lst, t_remember *new, int height)
{
    if (new->id > 300000)
    {
        free_cell(last_brain(*lst), height);
    }
    new->next = *lst;
	*lst = new;
}

t_remember	*make_brain(t_program p, int m, int score, int lastID)
{
	t_remember	*node;

	node = malloc(sizeof(t_remember));
	if (node)
	{
        node->id = lastID + 1;
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

int already_explored(t_remember *brain, t_program p, int *score, int *move)
{
    while (brain)
    {
        if (!mat_cmp(p, brain->matrix))
        {
            *score = brain->score;
            *move = brain->move;
            return (1);
        }
        brain = brain->next;
    }
    return (0);
}

int	change_player(int player)
{
	if (player == 1)
		return (2);
	else if (player == 2)
		return (1);
	return (42);
}
