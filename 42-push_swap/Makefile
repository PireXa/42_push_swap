# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 16:01:05 by fde-albe          #+#    #+#              #
#    Updated: 2022/05/23 09:41:53 by fde-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c \
		  ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_printf.c lis.c main.c \
		  ft_putstr.c ft_putunsigned.c ft_bzero.c ft_putchar.c ft_strlen.c pushes.c \
		  ft_calloc.c ft_puthex.c ft_strupper.c ft_itoa.c ft_putptr.c ft_uitoa.c \
		  rotates.c mvmnts_tester.c ft_memset.c ft_putsigned.c swaps.c ft_isdigit.c \
		  input_reader.c ft_split.c ft_lstindex.c \

OBJS	= $(addprefix objs/,$(SRCS:.c=.o))

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

NAME	= push_swap

all:		$(NAME)

objs/%.o: srcs/%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			@cc $(OBJS)	$(CFLAGS) -g -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
