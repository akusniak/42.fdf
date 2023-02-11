/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:07:41 by akusniak          #+#    #+#             */
/*   Updated: 2022/11/22 11:23:27 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dest;
	i = n - 1;
	if (dest > src)
	{
		while ((int)i >= 0)
		{
			d[i] = s[i];
			i--;
		}
		return (d);
	}
	else
	{
		d = ft_memcpy(dest, src, n);
		return (d);
	}
	return (d);
}
