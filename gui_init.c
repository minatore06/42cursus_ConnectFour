/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:40:34 by javellis          #+#    #+#             */
/*   Updated: 2023/05/18 15:38:57 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

t_image	load_sprite(t_program game, char *path)
{
	t_image		s;
	void			*ref;
	char			*pix;

	ref = mlx_xpm_file_to_image(game.mlx, path, &s.size.x, &s.size.y);
	pix = mlx_get_data_addr(ref, &s.bits_per_pixel, &s.line_size, &s.endian);
	s.reference = ref;
	s.pixels = pix;
	return (s);
}

void	ft_mlx_pixel_put(t_program *prog, int x, int y, int color)
{
	char	*i;
	int		y1;
	y1 = y * prog->buffer.line_size;
	i = prog->buffer.pixels + (y1 + x * (prog->buffer.bits_per_pixel / 8));
	*(unsigned int *)i = color;
}

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

int    ft_gui_init(t_program *prog)
{
	prog->win = 0;
    prog->mlx = mlx_init();
	prog->window = mlx_new_window(prog->mlx, prog->width * 64, ((prog->height + 1) *  64) + 20, "Connect4");
    prog->buffer = ft_new_image(prog->mlx, prog->width * 64, (prog->height) * 64);
    prog->player_img = load_sprite(*prog, "sprite/Red+Bg64x64.xpm");
    prog->empthy = load_sprite(*prog, "sprite/Bg64x64.xpm");
    prog->cpu = load_sprite(*prog, "sprite/Yellow+Bg64x64.xpm");
    prog->fiche = load_sprite(*prog, "sprite/RedOnly.xpm");
    prog->player_win = load_sprite(*prog, "sprite/RedWin64x64.xpm");
    prog->cpu_win = load_sprite(*prog, "sprite/YellowWin64x64.xpm");
    // ft_draw(prog);
    // mlx_put_image_to_window(prog->mlx, prog->window, prog->buffer.reference, 0, 0);
    return 0;
}
