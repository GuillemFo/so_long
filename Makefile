NAME = so_long


PATH_OBJ = tmp/

SRC = so_long.c

OBJ = $(addprefix $(PATH_OBJ),$(SRC:.c=.o))
	

CFLAGS = -Wall -Wextra -Werror -I./Include

all: makelib tmp $(NAME)

tmp:
	mkdir -p $(PATH_OBJ)

$(NAME): $(OBJ)
	cc $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)


makelib: 
	$(MAKE) -C ./libft 

$(PATH_OBJ)%.o: %.c ./Include/libft.h ./Include/so_long.h Makefile
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -c $< -o $@

re: fclean all

makefclean:
	$(MAKE) -C ./libft fclean

clean:
	rm -rf $(PATH_OBJ)

fclean: clean makefclean
	rm -rf $(NAME)

.PHONY: all re clean fclean