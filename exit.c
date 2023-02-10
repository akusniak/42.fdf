/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:49:26 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 18:17:48 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_errors(int error_code, t_fdf *fdf)
{
	(void)error_code;
	free(fdf);
	exit(1);
}

void	ft_exit_mlx(t_fdf *fdf)
{
	mlx_loop_end(fdf->screen.mlx.mlx);
	mlx_destroy_image(fdf->screen.mlx.mlx, fdf->screen.image.img);
	mlx_destroy_window(fdf->screen.mlx.mlx, fdf->screen.mlx.window);
	mlx_destroy_display(fdf->screen.mlx.mlx);
	free(fdf->screen.mlx.mlx);
	ft_free_tab_int(fdf->map.data, fdf->map.hauteur);
	free(fdf);
	exit(1);
}
