/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:27:46 by akusniak          #+#    #+#             */
/*   Updated: 2022/11/22 11:25:47 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	get_len(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	max;

	max = 0;
	s_len = ft_strlen(s);
	if (start < s_len)
		max = s_len - start;
	if (max > len)
		max = len;
	return (max);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	max;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	max = get_len(s, start, len);
	new = (char *)malloc(sizeof(char) * (max) + 1);
	if (!new)
		return (NULL);
	while (i < max)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
