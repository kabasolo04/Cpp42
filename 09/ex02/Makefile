NAME = Pmerge

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp \
		Pair.cpp \
		Pmerge.cpp \
		Vector.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re