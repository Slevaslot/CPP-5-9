SRC = Base.cpp main.cpp class/A.cpp class/B.cpp class/C.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++ -Wall -Wextra -Werror -std=c++98
NAME = Conversion

all:		$(NAME)

$(NAME):	$(SRC)
			$(CC) -o $(NAME) $(SRC)

fclean:
	rm $(NAME)

re: fclean all
