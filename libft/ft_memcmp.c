/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:48:03 by akusniak          #+#    #+#             */
/*   Updated: 2022/11/22 11:23:11 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*stk1;
	unsigned char	*stk2;

	stk1 = (unsigned char *) s1;
	stk2 = (unsigned char *) s2;
	i = 0;
	while (n > 0)
	{
		if (stk1[i] != stk2[i])
			return (stk1[i] - stk2[i]);
		i++;
		n--;
	}
	return (0);
}
