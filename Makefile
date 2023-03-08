# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 13:22:35 by lamasson          #+#    #+#              #
#    Updated: 2023/03/08 20:39:16 by lamasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= clang

CFLAGS	= -Wall -Wextra -Werror -g3

RM	= rm -rf

NAME	= fdf

SRCS	= main.c \
	  ft_parse.c \
	  ft_parse_utils.c \
	  ft_parse_colors.c \
	  ft_atoi_base.c

SRCS_BONUS =

OBJS	= ${SRCS:%.c=%.o}

OBJS_BONUS = ${SRCS_BONUS:%.c=%.o}

LIBFT	= ./libft/libft.a
MLX	= ./mlx_linux/libmlx.a

LIBS	= -L libft -lft -L mlx_linux -lmlx  -lXext -lX11 -lm -lz 

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} $(MLX) ${LIBFT} 
	@${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

all:	${NAME}

$(MLX)	:
	@make -C ./mlx_linux

$(LIBFT):
	@make -C ./libft
	

bonus:	${OBJS_BONUS}
	@make -C ./libft
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBS} -o ${NAME}

clean:
	@make -C ./libft clean
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@make -C ./libft fclean
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean bonus re
