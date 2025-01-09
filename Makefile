# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maw <maw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:46:09 by maw               #+#    #+#              #
#    Updated: 2025/01/01 14:50:27 by maw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  pipex

SRCS =  main.c \
		utils.c \
		utils2.c 
		


OBJS := $(SRCS:%.c=%.o)

FT_PRINTF = FT_PRINTF

FLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJS)
		$(MAKE) -C $(FT_PRINTF)
		gcc -fsanitize=address -g $(FLAGS) $(OBJS) $(FT_PRINTF)/libftprintf.a -o $(NAME)

all: $(NAME)

clean :
		$(RM) $(OBJS)
		# $(MAKE) -C $(LIBFT) clean
		$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
		$(RM) $(NAME)
		# $(RM) $(LIBFT)/libft.a
		$(RM) $(FT_PRINTF)/libftprintf.a

re: fclean all