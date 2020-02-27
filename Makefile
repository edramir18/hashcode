# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edramire <edramire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 00:51:07 by edramire          #+#    #+#              #
#    Updated: 2020/02/27 03:02:18 by edramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := hashcode

CC := gcc

A := a_example.txt
B := b_read_on.txt
C := c_incunabula.txt

SRCS := \
	show.c			\
	sort_books.c	\
	sort_libraries.c	\

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) main.c

debug:
	$(CC) -g -o $(NAME) $(SRCS) main.c
clean:
	rm -rf *.out
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o:%.c
	$(CC) -c $<

a: $(NAME)
	./$(NAME) $(A)

b: $(NAME)
	./$(NAME) $(B)

c: $(NAME)
	./$(NAME) $(C)
