/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kristori <kristori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:53:06 by kristori          #+#    #+#             */
/*   Updated: 2023/05/16 12:01:40 by kristori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connect4.h"

int	ft_random_start(t_program *prog)
{
	int	rnd;

	srand(time(0));
	rnd = rand() % 2;
	if (rnd == 0)
		prog->player = 1;
	else
		prog->player = 2;
	return (0);
}
