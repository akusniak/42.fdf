# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akusniak <akusniak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:51:15 by akusniak          #+#    #+#              #
#    Updated: 2023/02/10 19:01:30 by akusniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = fdf

SRCS = draw.c\
		events.c\
		exit.c\
		init.c\
		main.c\
		map.c\
		maths.c\
		point.c\
		render.c\
		utils.c

OBJS = $(SRCS:.c=.o)

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all :
clean :
fclean :
re :
.PHONY: all clean fclean re

// 1 ==> gcc -c *.c
// 2 ==>gcc -o NAME *.o

