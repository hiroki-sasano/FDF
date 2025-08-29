# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 20:56:52 by hisasano          #+#    #+#              #
#    Updated: 2025/08/29 17:39:18 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := fdf
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

SRCDIR      := src
OBJDIR      := obj
INCDIR      := include

SRC         := main.c\
				bresenham.c\
				draw_map.c\
				fdf_atoi.c\
				ft_split.c\
				ft_strlen.c\
				ft_substr.c\
				ft_strdup.c\
				get_next_line.c\
				get_next_line_utils.c\
				key_hook.c\
				load_map.c\
				mouse_hook.c\
				setup_hooks.c\
				count_cols.c\
				free_split.c
				
SRCS        := $(addprefix $(SRCDIR)/,$(SRC))
OBJS        := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

MLX_DIR     := ./minilibx-linux
MLX         := $(MLX_DIR)/libmlx.a
INCS        := -I$(MLX_DIR) -I$(INCDIR)
LIBS        := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

TEST_FILE   := 10-2.fdf

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	valgrind --leak-check=full ./$(NAME) $(TEST_FILE)

.PHONY: all clean fclean re  test
