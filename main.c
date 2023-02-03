/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kus <kus@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:42 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 12:28:46 by kus              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void ft_parsing(char *map)
{
    ft_suffix_check(map, ".fdf"); //libft
    ft_file_check(map); // libft
}

int	main(int argc, char **file)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
        ft_parsing(file[1]);
        fdf = ft_create_structure(file[1]);
	    ft_map(fdf);
        ft_create_window_env(fdf);
	    ft_create_image_env(fdf);
        ft_render(fdf);
        return (0);
    }
    else
    {
        ft_printf("Invalid entry form, please use : ./fdf  *.fdf\n");
        exit (1);
    }
}
