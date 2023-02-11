/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:42:25 by akusniak          #+#    #+#             */
/*   Updated: 2022/11/22 11:21:57 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_reverse(char *str, int length);
static int		is_neg(long nbr);
static size_t	get_len(long nbr);
static char		*ft_convert_ascii(long nbr, char *to_print_temp, int sign);

static void	ft_reverse(char *str, int length)
{
	int		start;
	int		end;
	char	swp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		swp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = swp;
		start++;
		end--;
	}
}

static int	is_neg(long nbr)
{
	if (nbr < 0)
		return (1);
	else
		return (0);
}

static size_t	get_len(long nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 0 && nbr <= 9)
		return (1);
	else
	{
		while (nbr > 9)
		{
			nbr /= 10;
			len++;
		}
		return (len + 1);
	}
}

static char	*ft_convert_ascii(long nbr, char *to_print_temp, int sign)
{
	char	*to_print;
	long	stk;
	long	long_nbr;
	size_t	i;

	to_print = to_print_temp;
	i = 0;
	long_nbr = nbr;
	if (long_nbr == 0)
		to_print[i++] = '0';
	while (long_nbr != 0)
	{
		stk = long_nbr % 10;
		if (stk > 9)
			to_print[i++] = (stk - 10) + 'a';
		else
			to_print[i++] = stk + '0';
		long_nbr = long_nbr / 10;
	}
	if (sign == 1)
		to_print[i++] = '-';
	to_print[i] = '\0';
	return (to_print);
}

char	*ft_itoa(int nbr)
{
	char	*to_print;
	size_t	len;
	long	long_nbr;
	int		sign;

	long_nbr = (long)nbr;
	len = get_len(long_nbr);
	sign = 0;
	if (is_neg(long_nbr))
	{
		len++;
		long_nbr *= -1;
		sign = 1;
	}
	to_print = (char *)malloc(sizeof(char) * len + 1);
	if (!to_print)
		return (NULL);
	ft_convert_ascii(long_nbr, to_print, sign);
	ft_reverse(to_print, len);
	return (to_print);
}
