/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kus <kus@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:17:42 by akusniak          #+#    #+#             */
/*   Updated: 2023/02/03 12:47:51 by kus              ###   ########.fr       */
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

char	*ft_read_copy(int fd, char *save);
char	*ft_extract(char *save);
char	*ft_new_save(char *save);
char	*ft_strjoin_gnl(char *save, char *buffer);
char	*ft_gnl(int fd);

#endif
