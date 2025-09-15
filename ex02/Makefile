NAME = fragtrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = ClapTrap.hpp \
			ScavTrap.hpp \
			FragTrap.hpp \

SRCS = ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		main.cpp \

OBJ = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(INCLUDES)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

make re: fclean all

.PHONY: all clean fclean re
