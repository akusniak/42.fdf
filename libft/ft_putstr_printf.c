/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:20:43 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:40 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_printf(const char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	return (ft_strlen((char *)str));
}
