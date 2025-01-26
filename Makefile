# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maw <maw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:46:09 by maw               #+#    #+#              #
#    Updated: 2025/01/26 01:13:46 by maw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  pipex

SRCS =  src/main.c \
		src/utils.c \
		src/parse.c \
		


OBJS := $(SRCS:%.c=%.o)

FT_PRINTF = FT_PRINTF

FLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJS)
		$(MAKE) -C $(FT_PRINTF)
		gcc $(FLAGS) $(OBJS) $(FT_PRINTF)/libftprintf.a -o $(NAME)

all: $(NAME)

clean :
		$(RM) $(OBJS)
		$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
		$(RM) $(NAME)
		$(RM) $(FT_PRINTF)/libftprintf.a

re: fclean all