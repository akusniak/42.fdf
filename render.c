/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:57:44 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 13:38:13 by akusniak         ###   ########.fr       */
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
	mlx_hook(fdf->screen.mlx.window, 17, (1L << 5), &ft_close, fdf);
	mlx_key_hook(fdf->screen.mlx.window, &ft_deal_key, fdf);
	mlx_loop(fdf->screen.mlx.mlx);
}

void	ft_print_help(void *mlx, void *window)
{
	char	*str;

	str = "[+] zoom   [-] zoom out";
	mlx_string_put(mlx, window, 13, 677, 0xFFFFFF, str);
	str = "[^] up   [v] down";
	mlx_string_put(mlx, window, 13, 692, 0xFFFFFF, str);
	str = "[<--] left   [-->] right";
	mlx_string_put(mlx, window, 13, 707, 0xFFFFFF, str);
	str = "[SPACE] alt +   [f] alt -   [r] alt initial";
	mlx_string_put(mlx, window, 13, 722, 0xFFFFFF, str);
	str = "[esc] quit";
	mlx_string_put(mlx, window, 13, 737, 0xFFFFFF, str);
}
