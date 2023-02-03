/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kus <kus@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:10:21 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 12:30:15 by kus              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_moove(float *x, float *y, int moove_x, int moove_y)
{
	*x += moove_x;
	*y += moove_y;
}

static void	ft_zoom(float *x1, float *y1, float *x2, float *y2, int zoom)
{
	*x1 *= zoom;
	*y1 *= zoom;
	*x2 *= zoom;
 	*y2 *= zoom;

}

void	ft_altitude(int *z, int altitude)
{
	*z *= altitude;
}

void	ft_conversion(t_fdf *fdf)
{
	ft_zoom(&fdf->point.x1, &fdf->point.y1, &fdf->point.x2, &fdf->point.y2, fdf->display.zoom);
	ft_iso(&fdf->point.x1, &fdf->point.y1, fdf->point.z1, fdf->display.altitude);
	ft_iso(&fdf->point.x2, &fdf->point.y2, fdf->point.z2, fdf->display.altitude);
	ft_moove(&fdf->point.x1, &fdf->point.y1, fdf->display.position_x, fdf->display.position_y);
	ft_moove(&fdf->point.x2, &fdf->point.y2, fdf->display.position_x, fdf->display.position_y);
}

void	ft_mlx_put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->screen.image.addr + (y * fdf->screen.image.line_length + x
			* (fdf->screen.image.bpp / 8));
	*(int *) dst = color;
}
