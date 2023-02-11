/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:38:31 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 15:06:28 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_alloc_tab(int hauteur, int largeur)
{
	int		i;
	int		**tab;

	i = 0;
	tab = malloc(sizeof(int *[hauteur]));
	if (tab == NULL)
		return (NULL);
	while (i < hauteur)
	{
		tab[i] = malloc(sizeof(int *[largeur]));
		if (tab[i] == NULL)
		{
			ft_free_tab_int(tab, i);
			return (NULL);
		}
		i = i + 1;
	}
	return (tab);
}
