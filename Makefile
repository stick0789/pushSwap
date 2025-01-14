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

NAME = push_swap

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar -rcs
RM	= rm -rf

SRCS 	= push_easy.c push_movements.c push_radix.c push_stacks.c push_utils.c \
	  push_utils2.c push_utils3.c push_validation.c push_swap.c push_list.c
	  
SRC_PATH = ./src/
OBJ_PATH = ./tmp/
H_PATH	 = ./headers

HEADERS  = -I$(H_PATH)

DIRSRC	 = $(addprefix $(SRC_PATH), $(SRCS))
OBJS 	 = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all	:	makelib $(OBJ_PATH) $(NAME)

makelib	:	
		$(MAKE) --silent -C libft --no-print-directory

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c Makefile libft/libft.a
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean	:
		$(RM) $(OBJ_PATH)
		$(MAKE) --silent -C libft clean

fclean	:
		$(RM) $(NAME) $(OBJ_PATH)
		$(MAKE) --silent -C libft fclean

re	:
		make fclean --silent
		make all --silent
		$(MAKE) all --silent -C libft
		
.PHONY	:	all clean fclean re

.SILENT	:
