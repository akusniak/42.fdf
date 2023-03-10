/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:22:51 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/12 13:52:25 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_init_map(t_fdf *fdf, char *argv)
{
	fdf->map.data = NULL;
	fdf->map.hauteur = 0;
	fdf->map.largeur = 0;
	fdf->map.map_path = argv;
	fdf->map.max_altitude = 0;
}

void	ft_init_display(t_fdf *fdf)
{
	fdf->display.position_x = 0;
	fdf->display.position_y = 0;
	fdf->display.zoom = 1;
	fdf->display.altitude = 1;
}

void	ft_init_point(t_fdf *fdf)
{
	fdf->point.x1 = 0;
	fdf->point.y1 = 0;
	fdf->point.z1 = 0;
	fdf->point.x2 = 0;
	fdf->point.y2 = 0;
	fdf->point.z2 = 0;
	fdf->point.color = 0;
}

void	ft_color(float z1, int *color, int max_altitude)
{
	float	percent;

	percent = z1 / max_altitude;
	if (z1 < 0)
	{
		if ((z1 * -1) < 0.2)
			*color = BLUE;
		else
			*color = NAVY_BLUE;
	}
	else if (z1 == 0)
		*color = BLUE;
	else if (percent > 0 && percent < 0.33)
		*color = GREEN;
	else if (percent >= 0.33 && percent < 0.88)
		*color = MARRON;
	else
		*color = 0xFFFFFF;
}

void	ft_draw_rect(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->screen.window.hauteur)
	{
		j = 0;
		while (j < fdf->screen.window.largeur)
		{
			ft_mlx_put_pixel(fdf, j, i, 0x000000);
			j = j + 1;
		}
		i = i + 1;
	}
}
