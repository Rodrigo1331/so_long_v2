# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 15:31:16 by rcruz-an          #+#    #+#              #
#    Updated: 2023/12/04 15:31:19 by rcruz-an         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	solong.a
BONUS_NAME	=	solong_bonus.a
SRCSDIR		=	srcs
OBJSDIR		=	objs

SRCS		=	so_long.c game_loop.c \
				game_over/exit_request.c game_over/free_playfield.c game_over/game_over.c \
				init_game/init_game.c init_game/set_counters.c init_game/set_flags.c init_game/set_path.c \
				init_game/game_init_render.c \
				playfield/check_playfield.c playfield/check_way_out.c playfield/get_playfield.c \
				events/game_events.c events/move_events.c events/collision_events.c \
				engine/put_sprite.c engine/move_sprite.c engine/collision.c \
				error/print_error.c error/exit_error.c \
				animation/animation.c animation/hero_animation.c \
				animation/exit_animation.c \

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lmlx -lXext -lX11 -lm -lbsd

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@ar rc $(NAME) $(OBJS)
	$(MAKE) -C mlx
	$(CC) $(NAME) -L./mlx/. $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o so_long
	@echo "Done!"

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -I. -O3 $(CFLAGS) -g -I.. -c $< -o $@

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJSDIR)
	rm -rf $(B_OBJSDIR)

fclean: clean
	rm -rf $(NAME) so_long
	rm -rf $(BONUS_NAME) so_long_bonus
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
