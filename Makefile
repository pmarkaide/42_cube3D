# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbejar-s <dbejar-s@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 11:57:01 by dbejar-s          #+#    #+#              #
#    Updated: 2024/10/28 12:07:17 by dbejar-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ./libmlx/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
SRCS = ./src/main.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

#######METER LIBFT
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re