NAME = so_long


PATH_OBJ = tmp/

SRC = so_long.c checker.c utils.c assembly_map.c move_player.c keys_to_moves.c \
	move_utils2.c checker_utils.c print_moves.c \

OBJ = $(addprefix $(PATH_OBJ),$(SRC:.c=.o))
	

CFLAGS = -Wall -Wextra -Werror -I./Include

all: makelib makeminilibx tmp $(NAME)

tmp:
	mkdir -p $(PATH_OBJ)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) ./libft/libft.a -framework OpenGL -framework AppKit -o $(NAME) -L MiniLibX -lmlx

makelib: 
	$(MAKE) -C ./libft bonus

makeminilibx:
	$(MAKE) -C ./MiniLibX

$(PATH_OBJ)%.o: %.c ./Include/libft.h ./Include/so_long.h ./Libft/libft.a Makefile
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -Imlx -g -c $< -o $@

re: fclean all

libftfclean:
	$(MAKE) -C ./libft fclean

minilibxfclean:
	$(MAKE) -C ./MiniLibX fclean

libftclean:
	$(MAKE) -C ./libft clean

clean: libftclean
	rm -rf $(PATH_OBJ)

fclean: clean libftfclean minilibxfclean
	rm -rf $(NAME)

.PHONY: all re clean fclean