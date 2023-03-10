/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:13:02 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 18:03:32 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

static int	ft_get_max_alt(int **data, int hauteur, int largeur)
{
	int	max;
	int	h;
	int	l;

	h = 0;
	max = data[0][0];
	while (h < hauteur)
	{
		l = 0;
		while (l < largeur)
		{
			if (data[h][l] > max)
				max = data[h][l];
			l = l + 1;
		}
		h = h + 1;
	}
	return (max);
}

static void	ft_get_map_information(t_fdf *fdf)
{
	char	*line;
	int		fd;

	fd = open(fdf->map.map_path, O_RDONLY);
	line = ft_gnl(fd);
	fdf->map.hauteur = fdf->map.hauteur + 1;
	fdf->map.largeur = ft_get_width(line, SPACE, NEW_LINE);
	while (line != NULL)
	{
		free(line);
		line = ft_gnl(fd);
		if (line)
			fdf->map.hauteur = fdf->map.hauteur + 1;
	}
	close(fd);
}

static void	ft_fill_tab(t_fdf *fdf)
{
	int		haut;
	int		larg;
	char	**ready_to_extract;
	char	*line;
	int		fd;

	fd = open(fdf->map.map_path, O_RDONLY);
	haut = 0;
	while (haut < fdf->map.hauteur)
	{
		line = ft_gnl(fd);
		ready_to_extract = ft_split(line, SPACE);
		free(line);
		larg = 0;
		while (larg < fdf->map.largeur)
		{
			fdf->map.data[haut][larg] = ft_atoi(ready_to_extract[larg]);
			free(ready_to_extract[larg]);
			larg = larg + 1;
		}
		free(ready_to_extract);
		haut = haut + 1;
	}
	close(fd);
}

void	ft_map(t_fdf *fdf)
{
	ft_get_map_information(fdf);
	fdf->map.data = ft_alloc_tab(fdf->map.hauteur, fdf->map.largeur);
	if (fdf->map.data == NULL)
		exit(1);
	ft_fill_tab(fdf);
	fdf->map.map_path = NULL;
	fdf->display.zoom = ft_minimum(1080 / fdf->map.hauteur / 2,
			1920 / fdf->map.largeur / 2);
	fdf->map.max_altitude = ft_get_max_alt(fdf->map.data,
			fdf->map.hauteur, fdf->map.largeur);
}
