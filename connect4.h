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

#endif