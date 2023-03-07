# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lamasson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 13:22:35 by lamasson          #+#    #+#              #
#    Updated: 2023/03/07 17:30:39 by lamasson         ###   ########.fr        #
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

LIBFT	= ./libft

LIB	= ./libft/libft.a

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	@make -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}

all:	${NAME}

bonus:	${OBJS_BONUS}
	@make -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJS_BONUS} ${LIB} -o ${NAME}

clean:
	@make -C ${LIBFT} clean
	@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	@make -C ${LIBFT} fclean
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean bonus re
