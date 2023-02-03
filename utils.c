/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:22:51 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 17:38:02 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/fdf.h"

void    ft_exit_mlx(t_fdf *fdf)
{
    mlx_loop_end(fdf->screen.mlx.mlx);
	mlx_destroy_image(fdf->screen.mlx.mlx, fdf->screen.image.img);
	mlx_destroy_window(fdf->screen.mlx.mlx, fdf->screen.mlx.window);
	mlx_destroy_display(fdf->screen.mlx.mlx);
	ft_free_tab_int(fdf->map.data, fdf->map.hauteur);
	free(fdf);
	exit(1);
}

void	ft_init_map(t_fdf *fdf, char *argv)
{
	fdf->map.data = NULL;
	fdf->map.fd = 0;
	fdf->map.hauteur = 0;
	fdf->map.largeur = 0;
	fdf->map.map_path = argv;
}

void	ft_init_display(t_fdf *fdf)
{
	fdf->display.position_x = 0;
	fdf->display.position_y = 0;
	fdf->display.zoom = 0;
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
	fdf->point.color = 0xFFFFFF;
}
