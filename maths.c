/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kus <kus@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:54:13 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 12:02:34 by kus              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void	ft_iso(float *x, float *y, int z, int altitude)
{
	ft_altitude(&z, altitude);
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

static int	ft_steps(int dx, int dy)
{
	int	steps;

	steps = 0;
	if (ft_abs(dx) > ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	return (steps);
}

void	ft_dda(t_fdf *fdf)
{
	int		dx;
	int		dy;
	int		steps;
	float	x_inc;
	float	y_inc;

	/* faire fonction color */
	fdf->point.color = (fdf->point.z2 || fdf->point.z1) ? 0xfc0345 : 0xBBFAFF;
	fdf->point.color = (fdf->point.z2 != fdf->point.z1) ? 0xfc031c : fdf->point.color;
	if (fdf->point.z2 < 0)
		fdf->point.color = 0xFF00007F;

	ft_conversion(fdf);
	dx = (fdf->point.x2) - (fdf->point.x1);
	dy = (fdf->point.y2) - (fdf->point.y1);
	steps = ft_steps(dx, dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	while ((int)(fdf->point.x2 - fdf->point.x1) ||
		(int)(fdf->point.y2 - fdf->point.y1))
	{
		if (ft_fit(fdf) == YES)
			ft_mlx_put_pixel(fdf, fdf->point.x1, fdf->point.y1, fdf->point.color);
		fdf->point.x1 = fdf->point.x1 + x_inc;
		fdf->point.y1 = fdf->point.y1 + y_inc;
	}
}
