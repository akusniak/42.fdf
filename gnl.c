/*#include "includes/get_next_line.h"

size_t	ft_len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substrmod(char *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	if (len > ft_len(s) - 1 - start)
		len = (ft_len(s) - start);
	if (start > ft_len(s) - 1)
		return (NULL);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= start && y < len)
		{
			dest[y] = s[i];
			y++;
		}
		i++;
	}
	dest[y] = 0;
	return (dest);
}

int	ft_reschr(char *res)
{
	size_t	i;
	char	c;

	i = 0;
	c = '\n';
	if (!res)
		return (-1);
	while (res[i])
	{
		if (res[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_strlcpymod(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1) < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strjoinmod(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		dest[i + y] = s2[y];
		y++;
	}
	dest[i + y] = 0;
	return (dest);
}
char	*ft_fillres(char *res, char *buffer)
{
	char	*temp;

	if (!res && buffer[0] != 0)
	{
		res = malloc(sizeof(char));
		res[0] = 0;
	}
	temp = ft_strjoinmod(res, buffer);
	free(res);
	return (temp);
}

char	*ft_filline(char *res)
{
	int		set;
	char	*line;

	set = ft_reschr(res);
	if (set == -1)
		set = ft_len(res) - 1;
	line = malloc(sizeof(char) * (set + 2));
	if (!line)
		return (NULL);
	ft_strlcpymod(line, res, (set + 2));
	return (line);
}

char	*ft_resetres(char *res)
{
	char	*temp;
	int		set;

	set = ft_reschr(res);
	if (set == -1)
	{
		free(res);
		return (NULL);
	}
	temp = ft_substrmod(res, (set + 1), (ft_len(res) - set - 1));
	free(res);
	return (temp);
}

char	*ft_read(int fd, char *res)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(res);
			res = NULL;
			break ;
		}
		buffer[size] = 0;
		res = ft_fillres(res, buffer);
		if (ft_reschr(res) >= 0)
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read(fd, res);
	if (!res)
		return (NULL);
	line = ft_filline(res);
	if (!line)
		return (NULL);
	res = ft_resetres(res);
	return (line);
}
*/

#include "includes/get_next_line.h"
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
/*
char	*ft_gnl(int fd)
{
	char		*line;
	static char	*global_save[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	global_save[fd] = ft_read_copy(fd, global_save[fd]);
	if (!global_save[fd])
		return (NULL);
	line = ft_extract(global_save[fd]);
	if (!line)
		return (NULL);
	global_save[fd] = ft_new_save(global_save[fd]);
	return (line);
}
*/
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
