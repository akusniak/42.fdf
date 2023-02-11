/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suffix_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:39:17 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 14:44:36 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_suffix_check(char *map, char *suffix)
{
	int	i;

	i = ft_strlen(map);
	if (map[i - 1] != suffix[3] || map[i - 2] != suffix[2]
		|| map[i - 3] != suffix[1] || map[i - 4] != suffix[0])
	{
		ft_printf("Invalid file, please use *%s\n", suffix);
		exit(1);
	}
}
