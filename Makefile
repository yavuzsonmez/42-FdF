# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 11:02:47 by ysonmez           #+#    #+#              #
#    Updated: 2021/08/27 13:44:56 by ysonmez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		fdf

SRCS			=		srcs/get_next_line.c \
						srcs/test.c \

OBJS			=		$(SRCS:.c=.o)

LIB				=		make bonus -C ./libft

CC				=		gcc

CFLAGS			=		-Wall -Werror -Wextra

RM				=		rm -f

$(NAME)			:		$(OBJS)
						$(LIB)
						$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

lib				:
						$(LIB)

clean			:
						$(RM) $(OBJS)

fclean			:		clean
						$(RM) $(NAME)
						cd ./libft && make fclean

all				:		$(NAME)

bonus			:		all

re				:		fclean all

.PHONY			:		clean fclean all re bonus
