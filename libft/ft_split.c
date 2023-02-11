/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:08:27 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 15:06:14 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nbr_mots(char *s, char c);
static int		ft_len_word(char *s, char c);
static char		*ft_gen_word(char *s, char c);
static char		**fill_split(char **tab, char const *s, char c);

static int	ft_nbr_mots(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_len_word(char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		len = len + 1;
		i++;
	}
	return (len);
}

static char	*ft_gen_word(char *s, char c)
{
	int		len;
	int		i;
	int		j;
	char	*new_word;

	i = 0;
	j = 0;
	len = ft_len_word(s, c);
	new_word = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_word)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		new_word[j] = s[i];
		i++;
		j++;
	}
	new_word[j] = '\0';
	return (new_word);
}

static char	**fill_split(char **tab, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + i) != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			tab[j] = ft_gen_word((char *)(s + i), c);
			if (tab[j] == NULL)
				return (ft_free_sub(tab, j));
			j++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (ft_nbr_mots((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	tab = fill_split(tab, s, c);
	if (!tab)
		return (NULL);
	return (tab);
}
