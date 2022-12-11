# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shifuuu <shifuuu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:55:52 by asaadane          #+#    #+#              #
#    Updated: 2022/12/11 20:41:11 by shifuuu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_itoa.c ft_printf_utils.c ft printf.c ft_puthex.c ft_putptr.c ft_putunsigned.c 

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar -r $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY : clean fclean all re
