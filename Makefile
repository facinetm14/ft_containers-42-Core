NAME = ft_container

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp 

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re