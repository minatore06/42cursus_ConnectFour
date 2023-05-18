/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:36:48 by ncortigi          #+#    #+#             */
/*   Updated: 2023/05/18 11:11:24 by kristori         ###   ########.fr       */
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

typedef struct  s_remember
{
    int     id;
    int		**matrix;
    int		move;
    int		score;
    void	*next;
}   t_remember;

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
    t_image player_win;
    t_image cpu_win;
    t_image fiche;
    t_remember *remember;
}   t_program;


void	    ft_draw_start_terminal(t_program *prog);
void	    ft_draw_grid_terminal(t_program *prog);
void		ft_draw_win_terminal(void);
void		ft_draw_lose_terminal(void);
int			check_input(int ac, char **av);
void	    take_input(t_program *data, char **av, int ac);
int	        ft_put(t_program *prog, int column);

int			is_playable(t_program p, int m);
int			is_winning_move(t_program p, int m, int player);
int			played_moves(t_program p);
int 		get_height(t_program p, int m);

t_program	p_copy(t_program p);
void		p_free(t_program p);

int    		ft_gui_init(t_program *prog);
int			ft_check_input_string(char *str);
int 		ft_draw(t_program *prog);
int			ft_close(void *param);
void		ft_free_all(t_program *program);
int     	ft_input(int button, int x, int y, t_program *param);
int     	create_trgb(int t, int r, int g, int b);
void		ft_mlx_pixel_put(t_program *prog, int x, int y, int color);
void    	ft_draw_grid(t_program *prog);

int	        ft_random_start(t_program *prog);
int 		**dup_matrix(t_program p);
void	    free_matrix(int **mat);
void		add_brain_front(t_remember **lst, t_remember *new, int height);
t_remember	*make_brain(t_program p, int m, int score, int lastID);
int 		already_explored(t_remember *brain, t_program p, int *score, int *move);
int 		mat_cmp(t_program p, int **maty);
int			destroy_enemy(t_program p, int player);
int			change_player(int player);

int         ai_plays(t_program p, int player, t_remember brain);

void        set_col(t_program p, int pl, int x, int y);
void        set_row(t_program p, int pl, int x, int y);
void        set_diag1(t_program p, int pl, int x, int y);
void        set_diag2(t_program p, int pl, int x, int y);

int			check_win(t_program p, int m, int pl);
int         check_win_ai(t_program p, int m, int pl, int verbose);

int         ft_mouse_move(int x, int y, void *param);

#endif
