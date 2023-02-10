/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:21 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 18:26:46 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	ft_fit(t_fdf *fdf)
{
	if (fdf->point.x1 >= 0 && fdf->point.x1 < fdf->screen.window.largeur
		&& fdf->point.y1 >= 0 && fdf->point.y1 < fdf->screen.window.hauteur)
		return (YES);
	else
		return (NO);
}

static void	ft_define_data(int hauteur, int largeur, t_fdf *fdf)
{
	fdf->point.x1 = largeur;
	fdf->point.y1 = hauteur;
	fdf->point.x2 = largeur;
	fdf->point.y2 = hauteur + 1;
	fdf->point.z1 = fdf->map.data[hauteur][largeur];
	fdf->point.z2 = fdf->map.data[hauteur + 1][largeur];
}

static void	ft_define_data_bis(int hauteur, int largeur, t_fdf *fdf)
{
	fdf->point.x1 = largeur;
	fdf->point.y1 = hauteur;
	fdf->point.x2 = largeur + 1;
	fdf->point.y2 = hauteur;
	fdf->point.z1 = fdf->map.data[hauteur][largeur];
	fdf->point.z2 = fdf->map.data[hauteur][largeur + 1];
}

void	ft_line(t_fdf *fdf, int hauteur, int largeur, int which_case)
{
	if (which_case == 1)
		ft_define_data(hauteur, largeur, fdf);
	else
		ft_define_data_bis(hauteur, largeur, fdf);
	ft_dda(fdf);
}

void	ft_draw(t_fdf *fdf)
{
	int	hauteur;
	int	largeur;

	hauteur = 0;
	while (hauteur < fdf->map.hauteur)
	{
		largeur = 0;
		while (largeur < fdf->map.largeur)
		{
			if (hauteur < fdf->map.hauteur - 1)
				ft_line(fdf, hauteur, largeur, 1);
			if (largeur < fdf->map.largeur - 1)
				ft_line(fdf, hauteur, largeur, 2);
			largeur = largeur + 1;
		}
		hauteur = hauteur + 1;
	}
	mlx_put_image_to_window(fdf->screen.mlx.mlx, fdf->screen.mlx.window,
		fdf->screen.image.img, 0, 0);
	ft_print_help(fdf->screen.mlx.mlx, fdf->screen.mlx.window);
}
