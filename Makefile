# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masase <masase@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:46:09 by maw               #+#    #+#              #
#    Updated: 2024/12/16 18:59:45 by masase           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  pipex

SRCS =  main.c \
		utils.c \
		


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
		# $(MAKE) -C $(LIBFT) clean
		$(MAKE) -C $(FT_PRINTF) clean

fclean: clean
		$(RM) $(NAME)
		# $(RM) $(LIBFT)/libft.a
		$(RM) $(FT_PRINTF)/libftprintf.a

re: fclean all