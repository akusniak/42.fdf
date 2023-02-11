/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:12 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 12:20:49 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_file_check(char *map)
{
	int		fd;
	int		r;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("open fail");
		exit(1);
	}
	line = malloc(sizeof(char) * 1);
	if (line == NULL)
	{
		ft_printf("malloc fail");
		exit(1);
	}
	r = read(fd, line, 1);
	if (r <= 0)
	{
		free(line);
		close(fd);
		exit(1);
	}
	free(line);
}
