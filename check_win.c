/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:29:54 by fracerba          #+#    #+#             */
/*   Updated: 2023/05/18 16:10:38 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int check_column(t_program p, int pl, int x, int y)
{
    int i;
    int count;

    count = 1;
    i = 1;
    while (i < 4 && (x + i) >= 0 && (x + i) < p.height)
    {
        if (p.matrix[x + i][y] == pl)
            count++;
        else
            break;
        i++;
    }
    if (count >= 4)
        return (1);
    return (0);
}

int check_row(t_program p, int pl, int x, int y)
{
    int i;
    int count;

    i = -1;
    count = 1;
    while (i > -4 && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x][y + i] == pl)
            count++;
        else
            break;
        i--;
    }
    i = 1;
    while (i < 4 && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x][y + i] == pl)
            count++;
        else
            break;
        i++;
    }
    if (count >= 4)
        return (1);
    return (0);
}

int check_diagonal1(t_program p, int pl, int x, int y)
{
    int i;
    int count;

    i = -1;
    count = 1;
    while (i > -4  && (x + i) >= 0 && (x + i) < p.height && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x + i][y + i] == pl)
            count++;
        else
            break;
        i--;
    }
    i = 1;
    while (i < 4  && (x + i) >= 0 && (x + i) < p.height && (y + i) >= 0 && (y + i) < p.width)
    {
        if (p.matrix[x + i][y + i] == pl)
            count++;
        else
            break;
        i++;
    }
    if (count >= 4)
        return (1);
    return (0);
}

int check_diagonal2(t_program p, int pl, int x, int y)
{
    int i;
    int j;
    int count;

    i = -1;
    j = 1;
    count = 1;
    while (i > -4 && j < 4 && (x + i) >= 0 && (x + i) < p.height && (y + j) >= 0 && (y + j) < p.width)
    {
        if (p.matrix[x + i][y + j] == pl)
            count++;
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
            count++;
        else
            break;
        i++;
        j--;
    }
    if (count >= 4)
        return (1);
    return (0);
}

int check_win(t_program p, int m, int pl)
{
    int     x;
    int     y;
    int     z;

    if (p.turn < 7)
        return (0);
    x = 0;
    y = m;
    while(x < p.height)
    {
        if(p.matrix[x][y] == pl)
            break;
        x++;
    }
    if ((x != 0 && p.matrix[x - 1][y] != 0) || x == p.height)
        return (-1);
    z = 0;
    if (check_row(p, pl, x, y))
    {
        set_row(p, pl, x, y);
        z = pl;
    }
    if (check_column(p, pl, x, y))
    {
        set_col(p, pl, x, y);
        z = pl;
    }
    if (check_diagonal1(p, pl, x, y))
    {
        set_diag1(p, pl, x, y);
        z = pl;
    }
    if (check_diagonal2(p, pl, x, y))
    {
        set_diag2(p, pl, x, y);
        z = pl;
    }
    return (z);
}

int check_win_ai(t_program p, int m, int pl, int verbose)
{
    int     x;
    int     y;

    (void)verbose;
    if (played_moves(p) < 7)
        return (0);
    x = 0;
    y = m;
    if (p.matrix[0][y] != 0)
        return (-1);
    while(x < p.height)
    {
        if(p.matrix[x][y] != 0)
            break;
        x++;
    }
    x--;
    if (check_row(p, pl, x, y) || check_column(p, pl, x, y) || check_diagonal1(p, pl, x, y) || check_diagonal2(p, pl, x, y))
        return(1);
    return (0);
}
