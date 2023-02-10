/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:36 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 13:41:29 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_create_window_env(t_fdf *fdf)
{
	fdf->screen.window.hauteur = 750;
	fdf->screen.window.largeur = 750;
	fdf->screen.mlx.mlx = mlx_init();
	fdf->screen.mlx.window = mlx_new_window(fdf->screen.mlx.mlx,
			fdf->screen.window.largeur, fdf->screen.window.hauteur, "FdF");
}

void	ft_create_image_env(t_fdf *fdf)
{
	fdf->screen.image.bpp = 0;
	fdf->screen.image.endian = 0;
	fdf->screen.image.line_length = 0;
	fdf->screen.image.img = mlx_new_image(fdf->screen.mlx.mlx,
			fdf->screen.window.hauteur, fdf->screen.window.largeur);
	fdf->screen.image.addr = mlx_get_data_addr(fdf->screen.image.img,
			&fdf->screen.image.bpp, &fdf->screen.image.line_length,
			&fdf->screen.image.endian);
}

t_fdf	*ft_create_structure(char *argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	ft_init_point(fdf);
	ft_init_map(fdf, argv);
	ft_init_display(fdf);
	return (fdf);
}
