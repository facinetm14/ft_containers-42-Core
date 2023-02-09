NAME = test

CC = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

#SRCS = test_random_access_iterator.cpp utils.cpp
#SRCS = test_reverse_iterator.cpp utils.cpp
SRCS = test_vector.cpp utils.cpp

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