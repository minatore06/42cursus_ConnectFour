/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:29:54 by fracerba          #+#    #+#             */
/*   Updated: 2023/05/16 11:50:51 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int check_column(t_program p, int pl, int x, int y)
{
    int i;
    int count;

    i = -1;
    count = 1;
    while (i > -4 && (x + i) >= 0 && (x + i) < p.width)
    {
        if (p.matrix[x + i][y] == pl)
            count++;
        else
            break;
        i--;
    }
    i = 1;
    while (i < 4 && (x + i) >= 0 && (x + i) < p.width)
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
    while (i > -4 && (y + i) >= 0 && (y + i) < p.height)
    {
        if (p.matrix[x][y + i] == pl)
            count++;
        else
            break;
        i--;
    }
    i = 1;
    while (i < 4 && (y + i) >= 0 && (y + i) < p.height)
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

int check_diagonal(t_program p, int pl, int x, int y)
{
    int i;
    int count;

    i = -1;
    count = 1;
    while (i > -4  && (x + i) >= 0 && (x + i) < p.width && (y + i) >= 0 && (y + i) < p.height)
    {
        if (p.matrix[x + i][y + i] == pl)
            count++;
        else
            break;
        i--;
    }
    i = 1;
    while (i < 4  && (x + i) >= 0 && (x + i) < p.width && (y + i) >= 0 && (y + i) < p.height)
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

int check_win(t_program p, int m, int pl)
{
    int     x;
    int     y;

    x = m;
    y = 0;
    if (p.turn < 7)
        return (0);
    while(p.matrix[x][y] != pl)
        y++;
    if(y != 0 && p.matrix[x][y - 1] != 0)
        return (-1);

    if (check_row (p, pl, x, y) || check_column(p, pl, x, y) || check_diagonal(p, pl, x, y))
        return (pl);
    return (0);
}
