# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaylor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:35:25 by jaylor            #+#    #+#              #
#    Updated: 2017/03/24 14:51:55 by jaylor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
HEADERS = includes

CFLAGS += -Wall -Werror -Wextra
CFLAGS += -I$(HEADERS)

FILESO =	ft_putchar.o \
			ft_putstr.o \
			ft_atoi.o \
			ft_itoa.o \
			ft_putnbr.o \
			ft_strndup.o \
			get_next_line.o \
			ft_memalloc.o \
			ft_strnew.o \
			ft_intlen.o \
			ft_strchr.o \
			ft_strrchr.o \
			ft_strdup.o \
			ft_abs.o \
			ft_strjoin.o \
			ft_strrev.o \
			ft_strcpy.o \
			ft_strlen.o \
			ft_putchar_fd.o \
			ft_putstr_fd.o \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FILESO) 
	ar rc $(NAME) $^ 

%.o: srcs/%.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(FILESO) 

fclean: clean
	rm -f $(NAME)

re: fclean all
