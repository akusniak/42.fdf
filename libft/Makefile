# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 10:27:15 by akusniak          #+#    #+#              #
#    Updated: 2023/02/03 15:16:09 by akusniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_minimum.c\
	ft_abs.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_calloc.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_strlen.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	get_next_line.c\
	ft_get_width.c\
	ft_alloc_tab.c\
	ft_free_sub.c\
	ft_free_tab_char.c\
	ft_free_tab_int.c\
	ft_file_check.c\
	ft_suffix_check.c\
	ft_printf.c\
	ft_print_id.c\
	ft_print_p.c\
	ft_print_u.c\
	ft_print_x.c\
	ft_print_xx.c\
	ft_putchar.c\
	ft_putstr_printf.c

BONUS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS:.c=.o)
DEP				= $(SRCS:.c=.d)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.d.o :
		$(CC) $(CFLAGS) -MM -MD -o $@ $<

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME) $(DEP)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus

-include $(DEP)
