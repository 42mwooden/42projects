# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwooden <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 17:16:02 by mwooden           #+#    #+#              #
#    Updated: 2017/03/03 21:53:06 by mwooden          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =\
	  create_3dp.c\
	  mat_bzero.c\
	  mat_identity.c\
	  mat_rotate.c\
	  mat_translate.c\
	  mat_scale.c\
	  mat_copy.c\
	  mat_mult.c\
	  mat_vector_mult.c\
	  put_img_pixel.c\
	  draw_line_3d.c\
	  mat_world.c\
	  mat_print.c

INCLUDES = -I gfx.h -I ../mlx/mlx.h

TARGET = libgfx.a

OBJS = $(SRCS:.c=.o)

CC = gcc
AR = ar

CFLAGS ?= -Wall -Wextra -Werror
CFLAGS += $(INCLUDES)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) rc $@ $^
	ranlib $@

./%.o: ./%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)
