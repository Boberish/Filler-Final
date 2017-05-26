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
NAME = filler
HEADERS = includes

CFLAGS += -Wall -Werror -Wextra
CFLAGS += -I$(HEADERS)

FILESO =	add_heat.o \
			color.o \
			map_checking.o \
			utilities.o \
			place_pieces.o \
			analyze.o \
			heat_map_maker.o \
			main.o \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(FILESO) $(LIBFT)
	gcc -o $(NAME) $^ $(CFLAGS)

%.o: srcs/%.c
	gcc -o $@ -c $< $(CFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(FILESO) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
