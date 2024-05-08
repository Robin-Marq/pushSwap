# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarquar <rmarquar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:36:23 by rmarquar          #+#    #+#              #
#    Updated: 2023/12/04 11:41:28 by rmarquar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
# -fsanitize=address -fno-omit-frame-pointer
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

SRCS	=	split.c handle_errors.c init_a_to_b.c init_b_to_a.c push_swap.c \
			push.c rev_rotate.c rotate.c sort_stacks.c sort_three.c stack_init.c \
			stack_utils.c swap.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
