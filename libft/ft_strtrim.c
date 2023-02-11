/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:21:31 by akusniak          #+#    #+#             */
/*   Updated: 2022/11/22 11:25:37 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_set(const char *s1, const char *set, int index);
static size_t	get_start(const char *s1, const char *set);
static size_t	get_last(const char *s1, const char *set);

static int	is_set(const char *s1, const char *set, int index)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1[index])
		{
			i++;
			return (1);
		}
		else
			i++;
	}
	return (0);
}

static size_t	get_start(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while ((is_set(s1, set, i) == 1) && (i < ft_strlen(s1)))
		i++;
	return (i);
}

static size_t	get_last(const char *s1, const char *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while ((is_set(s1, set, i) == 1) && (i > 0))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new;
	size_t		start;
	size_t		last;
	size_t		i;

	if (!s1 && !set)
		return (NULL);
	start = get_start((const char *)s1, (const char *)set);
	last = get_last((const char *)s1, (const char *)set) + 1;
	i = 0;
	if (start > last)
	{
		new = (char *)malloc(1);
		new[i] = 0;
		return (new);
	}
	new = (char *)malloc(sizeof(char) * (last - start) + 1);
	if (!new)
		return (NULL);
	while (start != last)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}
