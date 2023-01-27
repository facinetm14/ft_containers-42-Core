# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 13:47:38 by fakouyat          #+#    #+#              #
#    Updated: 2023/01/16 15:29:00 by fakouyat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_container

SRCS = main.cpp

CXX = c++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re