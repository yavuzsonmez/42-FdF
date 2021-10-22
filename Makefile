# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 11:02:47 by ysonmez           #+#    #+#              #
#    Updated: 2021/10/22 12:49:30 by ysonmez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		fdf

SRCS			=		srcs/fdf.c \
						srcs/get_data.c \
						srcs/get_next_line.c \
						srcs/utils.c \
						srcs/transform_data.c \
						srcs/draw.c \
						srcs/overlay.c \
						srcs/event_k.c \
						srcs/event_m.c \

OBJS			=		$(SRCS:.c=.o)

LIB				=		make bonus -C ./libft

MLX				=		make -C ./minilibx_macos

CC				=		gcc

CFLAGS			=		-Wall -Werror -Wextra

MLXFLAGS		=		-framework OpenGL -framework AppKit

RM				=		rm -f

$(NAME)			:		$(OBJS)
						$(LIB)
						$(MLX)
						$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx_macos/libmlx.a $(MLXFLAGS) -o $(NAME)

lib				:
						$(LIB)

mlx				:
						$(MLX)

clean			:
						$(RM) $(OBJS)

fclean			:		clean
						$(RM) $(NAME)
						cd ./libft && make fclean
						cd ./minilibx_macos && make clean

all				:		$(NAME)

bonus			:		all

re				:		fclean all

.PHONY			:		clean fclean all re bonus
