/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:17:53 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 12:17:11 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_strjoin_gnl(char *save, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!save)
	{
		save = malloc(sizeof(char));
		save[0] = '\0';
	}
	if (!save || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(save) + ft_strlen(buffer)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(save) + ft_strlen(buffer)] = '\0';
	free(save);
	return (str);
}

char	*ft_extract(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (free(save), NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_save(char *save)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	new = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new)
		return (NULL);
	new[0] = '\0';
	i++;
	j = 0;
	while (save[i])
		new[j++] = save[i++];
	if (new[0] == '\0')
		return (free(save), free(new), NULL);
	new[j] = '\0';
	free(save);
	return (new);
}

char	*ft_read_copy(int fd, char *save)
{
	char	*buffer;
	int		r_bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	r_bytes = 1;
	while (!ft_strrchr(save, '\n') && r_bytes != 0)
	{
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1 || (save == NULL && r_bytes == 0))
		{
			free (save);
			save = NULL;
			break ;
		}
		buffer[r_bytes] = '\0';
		save = ft_strjoin_gnl(save, buffer);
	}
	free (buffer);
	return (save);
}

char	*ft_gnl(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_copy(fd, save);
	if (!save)
		return (NULL);
	line = ft_extract(save);
	if (!line)
		return (NULL);
	save = ft_new_save(save);
	return (line);
}
