# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maw <maw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 15:46:09 by maw               #+#    #+#              #
#    Updated: 2024/12/05 16:39:18 by maw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  pipex

SRCS =  main.c \
		


OBJS := $(SRCS:%.c=%.o)

LIBFT = LIBFT

FLAGS = -Wall -Werror -Wextra

RM = rm -f

$(NAME): $(OBJS)
		$(MAKE) -C $(LIBFT)
		gcc $(FLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

all: $(NAME)

clean :
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBFT) clean

fclean: clean
		$(RM) $(NAME)
		$(RM) $(LIBFT)/libft.a

re: fclean all