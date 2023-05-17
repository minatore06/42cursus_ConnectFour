/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:36:48 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/17 10:11:42 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include "minilibx-linux/mlx.h"

typedef struct s_vector
{
	int	x;
	int	y;
}   t_vector;

typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
	char		*path;
}	t_image;

typedef struct s_program
{
    int gui;
    int player;
    int height;
    int width;
    int **matrix;
    int     win;
    void	*mlx;
	void	*window;
    int turn;
    t_image buffer;
    t_image empthy;
    t_image player_img;
    t_image cpu;
}   t_program;

typedef struct  s_remember
{
    int		**matrix;
    int		move;
    int		score;
    void	*next;
}   t_remember;

void	    ft_draw_start_terminal(t_program *prog);
void	    ft_draw_grid_terminal(t_program *prog);
int			check_input(int ac, char **av);
void	take_input(t_program *data, char **av, int ac);
int	        ft_put(t_program *prog, int column);

int			is_playable(t_program p, int m);
int			is_winning_move(t_program p, int m, int player);
int			played_moves(t_program p);
int 		get_height(t_program p, int m);

t_program	p_copy(t_program p);
void		p_free(t_program p);

int    ft_gui_init(t_program *prog);
int ft_check_input_string(char *str);
int ft_draw(t_program *prog);
int	ft_close(void *param);
void	ft_free_all(t_program *program);
int     ft_input(int button, int x, int y, t_program *param);
int     create_trgb(int t, int r, int g, int b);
void	ft_mlx_pixel_put(t_program *prog, int x, int y, int color);
void    ft_draw_grid(t_program *prog);
int	        ft_random_start(t_program *prog);
int 		**dup_matrix(t_program p);
void		add_brain_front(t_remember **lst, t_remember *new);
t_remember	*make_brain(t_program p, int m, int score);
int 		already_explored(t_remember *brain, t_program p, int *score);
int 		mat_cmp(t_program p, int **maty);

void		ai_plays(t_program p, int player);

int			check_win(t_program p, int m, int pl);
#endif
