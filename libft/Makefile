# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 15:56:37 by rcruz-an          #+#    #+#              #
#    Updated: 2023/08/03 11:58:28 by rcruz-an         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRCSDIR		=	srcs
OBJSDIR		=	objs
INCLUDES	=	includes

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		=	ft_printf/ft_printf.c ft_printf/ft_printf_chars.c ft_printf/ft_printf_numbers.c ft_printf/ft_printf_utils.c \
			 	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
				libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memcmp.c libft/ft_putchar_fd.c libft/ft_split.c \
				libft/ft_strlcat.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_atoi.c libft/ft_isalpha.c \
				libft/ft_itoa.c libft/ft_memcpy.c libft/ft_putendl_fd.c libft/ft_strchr.c libft/ft_strlcpy.c \
				libft/ft_strnstr.c libft/ft_tolower.c libft/ft_bzero.c libft/ft_isascii.c \
				libft/ft_memmove.c libft/ft_putnbr_fd.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strrchr.c \
				libft/ft_toupper.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memchr.c libft/ft_memset.c  \
				libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_striteri.c libft/ft_strmapi.c \
				utils/ft_get_digits.c

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test
