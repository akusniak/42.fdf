/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:02 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 16:01:21 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/fdf.h"

static void	ft_get_map_information(t_fdf *fdf)
{
	char	*line;

	fdf->map.fd = open(fdf->map.map_path, O_RDONLY);
	if (fdf->map.fd == -1)
		ft_errors(OPEN_F, fdf);
	if (fdf->map.fd == 0)
		ft_errors(OPEN_E, fdf);
	line = ft_gnl(fdf->map.fd);
	fdf->map.hauteur = fdf->map.hauteur + 1;
	fdf->map.largeur = ft_get_width(line, SPACE, NEW_LINE); // dans libft
	while (line != NULL)
	{
		free(line);
		line = ft_gnl(fdf->map.fd);
		if (line)
			fdf->map.hauteur = fdf->map.hauteur + 1;
	}
}

static void	ft_fill_tab(t_fdf *fdf)
{
	int		haut;
	int		larg;
	char	**ready_to_extract;
	char	*line;

	fdf->map.fd = open(fdf->map.map_path, O_RDONLY);
	if (fdf->map.fd < 0)
		ft_errors(OPEN_F, fdf);
	haut = 0;
	while (haut < fdf->map.hauteur)
	{
		larg = 0;
		line = ft_gnl(fdf->map.fd);
		ready_to_extract = ft_split(line, SPACE);
		free(line);
		while (larg < fdf->map.largeur)
		{
			fdf->map.data[haut][larg] = ft_atoi(ready_to_extract[larg]);
			larg = larg + 1;
		}
		ft_free_tab_char(ready_to_extract, fdf->map.largeur); // ok -- dans libft
		haut = haut + 1;
	}
	close(fdf->map.fd);
}

void	ft_map(t_fdf *fdf)
{
    ft_get_map_information(fdf);
	fdf->map.data = ft_alloc_tab(fdf->map.hauteur, fdf->map.largeur); // libft
	ft_fill_tab(fdf);
	fdf->map.map_path = NULL;
	if (fdf->map.fd == -1)
		ft_errors(CLOSE, fdf);
	fdf->display.zoom = ft_minimum(750 / fdf->map.hauteur / 2, 750 / fdf->map.largeur / 2); // lib
}
