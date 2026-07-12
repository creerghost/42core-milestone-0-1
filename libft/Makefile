# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlnikola <vlnikola@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 22:52:41 by vlnikola          #+#    #+#              #
#    Updated: 2025/11/13 01:50:32 by vlnikola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_is_group.c \
	ft_print_group.c \
	ft_atoi_itoa.c \
	ft_fniteri.c \
	ft_mallocated_1.c \
	ft_mallocated_2.c \
	ft_strings_1.c \
	ft_strings_2.c \
	ft_mem_group_1.c \
	ft_mem_group_2.c \
	ft_to_upper_lower.c \
	ft_split.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

BONUS = ft_1_bonus.c \
	ft_2_bonus.c \

BONUS_OBJECTS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(BONUS_OBJECTS)
fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

#so: $(OBJECTS)
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES)
#	gcc -nostartfiles -shared -o libft.so $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: all clean fclean re bonus
