# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:47:40 by jaacosta          #+#    #+#              #
#    Updated: 2024/12/02 17:58:36 by jaacosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -rcs
RM	= rm -f

SRC 	=

HEADER	= push_swap.h

OBJS	= $(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)	push_swap.h
		$(AR) $(NAME) $(OBJS)

%.o	:	%.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME) $(OBJS)

re	:
		$(RM) $(NAME) $(OBJS)
		make all
