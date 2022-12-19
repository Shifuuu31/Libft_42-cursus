# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaadane <asaadane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:55:52 by asaadane          #+#    #+#              #
#    Updated: 2022/12/16 05:10:38 by asaadane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c ft_printf_tools.c ft_printf_tools_x.c 

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar -rc $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY : clean fclean all re
