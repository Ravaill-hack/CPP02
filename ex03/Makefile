NAME = ex03

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_FILES = \
	main.cpp \
	Fixed.cpp \
	Point.cpp \
	bsp.cpp \

OBJS = $(SRCS_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re