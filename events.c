/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:49:18 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 10:34:48 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	ft_deal_key(int key, t_fdf *fdf)
{
	if (key == MAX)
		fdf->display.zoom += 1;
	if (key == MINUS)
		fdf->display.zoom -= 1;
	if (key == UP)
		fdf->display.position_y -= 7;
	if (key == DOWN)
		fdf->display.position_y += 7;
	if (key == RIGHT)
		fdf->display.position_x += 7;
	if (key == LEFT)
		fdf->display.position_x -= 7;
	if (key == SPA)
		fdf->display.altitude += 1;
	if (key == R)
		fdf->display.altitude = 1;
	if (key == F)
		fdf->display.altitude -= 1;
	if (key == ESC)
		ft_exit_mlx(fdf);
	// peut etre clear window ici ??
	//mlx_clear_window(fdf->screen.mlx.mlx, fdf->screen.mlx.window);
	ft_create_image_env(fdf);
	ft_draw(fdf);
	return (0);
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}
