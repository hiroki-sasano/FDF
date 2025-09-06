# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hisasano <hisasano@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 20:56:52 by hisasano          #+#    #+#              #
#    Updated: 2025/09/06 17:32:37 by hisasano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := fdf
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

SRCDIR      := src
OBJDIR      := obj
INCDIR      := include

SRC         := main.c bresenham.c draw_map.c key_hook.c load_map.c\
				setup_hooks.c count_cols.c free_split.c reset_view.c\
				project_point.c parse_row.c measure_map.c\
				fdf_atoi.c ft_split.c ft_strlen.c ft_substr.c ft_strdup.c\
				ft_strchr.c my_strtol.c get_next_line.c get_next_line_utils.c

SRCS        := $(addprefix $(SRCDIR)/,$(SRC))
OBJS        := $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_DIR  := ./minilibx-linux
	MLX      := $(MLX_DIR)/libmlx.a
	INCS     := -I$(MLX_DIR) -I$(INCDIR)
	LIBS     := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
	MLX_DIR  := ./minilibx_macos
	MLX      := $(MLX_DIR)/libmlx.a
	INCS     := -I$(MLX_DIR) -I$(INCDIR)
	LIBS     := -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

TEST_FILE   := test4_4.fdf
TEST_PATH   := test_maps/$(TEST_FILE)

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(LIBS) -o $@

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
	valgrind --leak-check=full ./$(NAME) $(TEST_PATH)
	
.PHONY: all clean fclean re test
