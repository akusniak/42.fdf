/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:57:44 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 10:34:35 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	ft_close(t_fdf *fdf)
{
	ft_exit_mlx(fdf);
	return (0);
}

void	ft_render(t_fdf *fdf)
{
    ft_draw(fdf);
	mlx_loop_hook(fdf->screen.mlx.mlx, &handle_no_event, fdf);
    mlx_hook(fdf->screen.mlx.window, 17, (1L<<5), &ft_close, fdf); // work mais pas propre
	mlx_key_hook(fdf->screen.mlx.window, &ft_deal_key, fdf);
    mlx_loop(fdf->screen.mlx.mlx);
}

void	ft_print_help(void *mlx, void *window)
{
	mlx_string_put(mlx, window, 13, 677, 0xFFFFFF, "[+] zoom   [-] zoom out");
	mlx_string_put(mlx, window, 13, 692, 0xFFFFFF, "[^] up   [v] down");
	mlx_string_put(mlx, window, 13, 707, 0xFFFFFF, "[<--] left   [-->] right");
	mlx_string_put(mlx, window, 13, 722, 0xFFFFFF, "[SPACE] alt +   [f] alt -   [r] alt initial");
	mlx_string_put(mlx, window, 13, 737, 0xFFFFFF, "[esc] quit");
}
