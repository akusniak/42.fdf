/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:38:43 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 14:38:45 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab_char(char **data, int i)
{
	int	y;

	y = 0;
	while (y < i)
	{
		free(data[y]);
		y = y + 1;
	}
	free(data);
}
