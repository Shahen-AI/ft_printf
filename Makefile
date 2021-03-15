# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ster-min <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 17:22:57 by ster-min          #+#    #+#              #
#    Updated: 2021/02/18 17:23:00 by ster-min         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= $(shell find "." -name "*.c")
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
AR		= ar csr

.c.o 	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME)	: ${OBJS}
		 ${AR} ${NAME} ${OBJS}

all :	${NAME}

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re .c.o
