/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:34:07 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 14:40:27 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(unsigned int nbr);
static void	ft_print(unsigned int number);

static int	get_int_len(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_print(unsigned int number)
{
	if (number > 9)
	{
		ft_print(number / 10);
		ft_putchar(number % 10 + '0');
	}
	else
		ft_putchar(number + '0');
}

int	ft_print_u(unsigned int nbr)
{
	size_t		len;

	len = get_int_len(nbr);
	ft_print(nbr);
	return (len);
}
