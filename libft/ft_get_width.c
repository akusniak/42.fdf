/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:49 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:50 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_width(char *line, char separator, char end_of_line)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	while (line[i] != end_of_line)
	{
		while (line[i] == separator && line[i] != end_of_line)
			i = i + 1;
		if (line[i] != separator && line[i] != end_of_line)
			l = l + 1;
		while (line[i] != separator && line[i] != end_of_line)
			i = i + 1;
	}
	return (l);
}
