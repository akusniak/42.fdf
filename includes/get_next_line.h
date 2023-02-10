/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:17:42 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/10 11:33:15 by akusniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*ft_strjoin_gnl(char *save, char *buffer);
char	*ft_gnl(int fd);

/*char	*get_next_line(int fd);
size_t	ft_len(char *s);
char	*ft_substrmod(char *s, unsigned int start, size_t len);
char	*ft_strjoinmod(char *s1, char *s2);
int		ft_reschr(char *res);
void	ft_strlcpymod(char *dst, char *src, size_t size);
*/
#endif
