NAME = BinarySpacePartitioning

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		bsp.cpp \
		Point.cpp \
		Fixed.cpp

all: $(NAME)

$(NAME):
	c++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
	
fclean: clean

re: fclean all

.PHONY: all clean fclean re