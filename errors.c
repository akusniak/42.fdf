/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kus <kus@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:49:26 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/09 19:14:58 by kus              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/fdf.h"

void    ft_errors(int error_code, t_fdf *fdf)
{
    if (error_code == FDF_INIT)
        ft_printf("FDF structure allocation failed");
    if (error_code == OPEN_F)
    {
        ft_printf("Open fail");
        close(fdf->map.fd);
    }
    if (error_code == READ)
    {
        ft_printf("Read fail");
        close(fdf->map.fd);
    }
    if (error_code == OPEN_E)
    {
        ft_printf("Empty file");
        close(fdf->map.fd);
    }
    if (error_code == MALLOC_DATA)
    {
        ft_printf("Memory allocation failed");
        close(fdf->map.fd);
        free(fdf->map.data);
    }
    if (error_code == MALLOC_DATA_BIS)
    {
        ft_printf("Memory allocation failed");
        close(fdf->map.fd);
    }
    if (error_code == CLOSE)
    {
        ft_printf("Close fail");
        ft_free_tab_int(fdf->map.data, fdf->map.hauteur);
    }
    if (error_code == MLX_CRASH)
    {
        ft_printf("MLX crash");
        ft_free_tab_int(fdf->map.data, fdf->map.hauteur);
        free(fdf->screen.mlx.mlx);
    }
    free(fdf);
    exit(1);
}
