/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kus <kus@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:36 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 12:28:55 by kus              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_create_window_env(t_fdf *fdf)
{
	fdf->screen.window.hauteur = 750;
	fdf->screen.window.largeur = 750;
	//set NULL
	fdf->screen.mlx.mlx = mlx_init();
	if (fdf->screen.mlx.mlx == 0)
		ft_errors(MLX_CRASH, fdf);
	fdf->screen.mlx.window = mlx_new_window(fdf->screen.mlx.mlx,fdf->screen.window.largeur, fdf->screen.window.hauteur, "FdF");
	if (fdf->screen.mlx.window == 0)
		ft_errors(MLX_CRASH, fdf);

}

void ft_create_image_env(t_fdf *fdf)
{
	fdf->screen.image.bpp = 0;
	fdf->screen.image.endian = 0;
	fdf->screen.image.line_length = 0;
	//set NULL
	fdf->screen.image.img = mlx_new_image(fdf->screen.mlx.mlx,
			fdf->screen.window.hauteur, fdf->screen.window.largeur);
	if (fdf->screen.image.img == 0)
		ft_errors(MLX_CRASH, fdf);
	fdf->screen.image.addr = mlx_get_data_addr(fdf->screen.image.img,
			&fdf->screen.image.bpp, &fdf->screen.image.line_length,
			&fdf->screen.image.endian);
	if (fdf->screen.image.addr == 0)
		ft_errors(MLX_CRASH, fdf);
}

t_fdf	*ft_create_structure(char *argv)
{
	t_fdf		*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
        ft_errors(FDF_INIT, fdf);
	ft_init_point(fdf);
	ft_init_map(fdf, argv);
	ft_init_display(fdf);
	return (fdf);
}
