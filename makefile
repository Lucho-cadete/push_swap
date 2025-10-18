# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 12:42:12 by lucho             #+#    #+#              #
#    Updated: 2025/10/18 18:07:04 by luimarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

vpath %.c pushswap

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = command_push.c \
		command_reverse_rotate.c \
		command_rotate.c \
		command_swap.c \
		sort_small.c \
		sort_utils.c \
		indexing.c \
		parsing_fill_stack.c \
		parsing_validate_args.c \
		push_swap.c \
		pushing_back_to_a.c \
		pushing_chunks_to_b.c \
		libft_functions.c
OBJ_DIR = o_files
OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
RM = rm -f

all: $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "🧹 Object files removed!"
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "🗑️  Full clean done!"
	@$(RM) $(NAME)

re: fclean all
	@echo "🔁 Rebuilding project..."

.PHONY: all clean fclean re
