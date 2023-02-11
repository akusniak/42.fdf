/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:02:18 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:31 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int nbr);
static void	ft_print(int nbr);

static int	get_int_len(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
		len = 2;
	while (nbr / 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_print(int nbr)
{
	if (nbr > 9)
	{
		ft_print(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + 48);
}

int	ft_print_id(int nbr)
{
	size_t	len;

	len = get_int_len(nbr);
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	ft_print(nbr);
	return (len);
}
