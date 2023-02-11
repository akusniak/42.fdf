/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:36 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 17:33:16 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_create_window_env(t_fdf *fdf)
{
	fdf->screen.window.hauteur = 1080;
	fdf->screen.window.largeur = 1920;
	fdf->screen.mlx.mlx = mlx_init();
	if (fdf->screen.mlx.mlx == NULL)
		ft_errors(MLX_CRASH, fdf);
	fdf->screen.mlx.window = mlx_new_window(fdf->screen.mlx.mlx,
			fdf->screen.window.largeur, fdf->screen.window.hauteur, "FdF");
	if (fdf->screen.mlx.window == NULL)
		ft_errors(WIN_CRASH, fdf);
}

void	ft_create_image_env(t_fdf *fdf)
{
	fdf->screen.image.bpp = 0;
	fdf->screen.image.endian = 0;
	fdf->screen.image.line_length = 0;
	fdf->screen.image.img = mlx_new_image(fdf->screen.mlx.mlx,
			fdf->screen.window.largeur, fdf->screen.window.hauteur);
	fdf->screen.image.addr = mlx_get_data_addr(fdf->screen.image.img,
			&fdf->screen.image.bpp, &fdf->screen.image.line_length,
			&fdf->screen.image.endian);
}

t_fdf	*ft_create_structure(char *argv)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		exit(1);
	ft_init_point(fdf);
	ft_init_map(fdf, argv);
	ft_init_display(fdf);
	return (fdf);
}
