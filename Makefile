NAME = so_long


PATH_OBJ = tmp/

SRC = so_long.c checker.c utils.c

OBJ = $(addprefix $(PATH_OBJ),$(SRC:.c=.o))
	

CFLAGS = -Wall -Wextra -Werror -I./Include

all: makelib makeminilibx tmp $(NAME)

tmp:
	mkdir -p $(PATH_OBJ)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) ./libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

makelib: 
	$(MAKE) -C ./libft 

makeminilibx:
	$(MAKE) -C ./MiniLibX

$(PATH_OBJ)%.o: %.c ./Include/libft.h ./Include/so_long.h Makefile
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -Imlx -g -c $< -o $@

re: fclean all

makefclean:
	$(MAKE) -C ./libft fclean

makefcleanminilibx:
	$(MAKE) -C ./MiniLibX fclean

clean:
	rm -rf $(PATH_OBJ)

fclean: clean makefclean makefcleanminilibx
	rm -rf $(NAME)

.PHONY: all re clean fclean