# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kus <kus@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:51:15 by akusniak          #+#    #+#              #
#    Updated: 2023/02/11 10:48:35 by kus              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

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
DEP = $(SRCS:.c=.d)

LIB = make bonus -C ./libft
MLX = make -C ./minilibx

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.d.o : 
		$(CC) $(CFLAGS) -MM -MD -o $@ $<
$(NAME) : $(OBJS)
				$(LIB)
				$(MLX)
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx/libmlx_Linux.a $(MLXFLAGS) -o $(NAME)

lib :
		$(LIB)

mlx :
		$(MLX)

all :
		$(NAME)

bonus : all

clean :
		$(RM) $(OBJS) $(DEP)

fclean : clean
		$(RM) $(NAME)
		cd ./libft && make fclean
		cd ./minilibx && make clean

re : fclean all

.PHONY: all clean fclean re lib mlx

-include $(DEP)
