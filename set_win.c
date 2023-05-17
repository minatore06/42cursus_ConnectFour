/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:35:56 by fracerba          #+#    #+#             */
/*   Updated: 2023/05/17 16:36:00 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

void set_col(t_program p, int pl, int x, int y)
{
    int i;

    i = 1;
    p.matrix[x][y] = pl + 2;
    while (i < 4 && (x + i) >= 0 && (x + i) < p.height)
    {
        if (p.matrix[x + i][y] == pl)
            p.matrix[x + i][y] = pl + 2;
        else
            break;
        i++;
    }
}

void set_row(t_program p, int pl, int x, int y)
{
    int i;

    i = -1;
    p.matrix[x][y] = pl + 2;
    while (i > -4 && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x][y + i] == pl)
            p.matrix[x][y + i] = pl + 2;
        else
            break;
        i--;
    }
    i = 1;
    while (i < 4 && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x][y + i] == pl)
            p.matrix[x][y + i] = pl + 2;
        else
            break;
        i++;
    }
}

void set_diag1(t_program p, int pl, int x, int y)
{
    int i;

    i = -1;
    p.matrix[x][y] = pl + 2;
    while (i > -4  && (x + i) >= 0 && (x + i) < p.height && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x + i][y + i] == pl)
            p.matrix[x + i][y + i] = pl + 2;
        else
            break;
        i--;
    }
    i = 1;
    while (i < 4  && (x + i) >= 0 && (x + i) < p.height && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x + i][y + i] == pl)
            p.matrix[x + i][y + i] = pl + 2;
        else
            break;
        i++;
    }
}

void set_diag2(t_program p, int pl, int x, int y)
{
    int i;
    int j;

    i = -1;
    j = 1;
    p.matrix[x][y] = pl + 2;
    while (i > -4 && j < 4 && (x + i) >= 0 && (x + i) < p.height && (y + j) >= 0 && (y + j) < p.width)
    {
        if (p.matrix[x + i][y + j] == pl)
            p.matrix[x + i][y + j] = pl + 2;
        else
            break;
        i--;
        j++;
    }
    i = 1;
    j = -1; 
    while (i < 4 && j > -4 && (x + i) >= 0 && (x + i) < p.height && (y + j) >= 0 && (y + j) < p.width)
    {
        if (p.matrix[x + i][y + j] == pl)
            p.matrix[x + i][y + j] = pl + 2;
        else
            break;
        i++;
        j--;
    }
}
