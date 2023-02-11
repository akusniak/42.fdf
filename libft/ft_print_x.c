/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:02:07 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 15:18:19 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(unsigned long nbr)
{
	int	i;

	i = 1;
	while (nbr / 16)
	{
		i++;
		nbr /= 16;
	}
	return (i);
}

static char	*ft_print(unsigned long nbr)
{
	char	*base;
	char	*to_print;
	int		i;

	base = "0123456789abcdef";
	to_print = malloc(sizeof(char) * ft_get_len(nbr) + 1);
	if (!to_print)
		return (NULL);
	i = ft_get_len(nbr);
	to_print[i--] = '\0';
	while (i >= 0)
	{
		to_print[i--] = base[nbr % 16];
		nbr = nbr / 16;
	}
	return (to_print);
}

int	ft_print_x(unsigned int nbr)
{
	char	*to_print;
	int		i;

	to_print = ft_print((unsigned long)nbr);
	i = ft_strlen(to_print);
	ft_putstr_printf(to_print);
	free(to_print);
	return (i);
}
