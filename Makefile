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

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MLXFLAGS = -lX11 -lXext -lm

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

LIB = make bonus -C ./libft ## -C indique à make d'executer un autre makefile
MLX = make -C ./minilibx-linux

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
				$(LIB)
				$(MLX)
				$(CC) $(CFLAGS) libft/libft.a minilibx-linux/libmlx_Linux.a  $(MLXFLAGS) -o $(NAME)

lib : $(LIB)

mlx : $(MLX)

all : $(NAME)

bonus : all

clean : $(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)
			cd ./libft && make fclean
			cd ./minilibx_linux && make clean

re : fclean all

.PHONY: all clean fclean re lib mlx