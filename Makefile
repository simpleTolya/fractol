
NAME = fractol

SRCS = fractol.c ft_color.c ft_fractal_iter.c \
		ft_utils.c ft_fractol_init.c ft_actions.c
OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -Ofast

all: $(NAME)

%.o: %.c fractol.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: all
