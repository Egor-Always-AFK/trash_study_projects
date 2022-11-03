NAME = review

CC = clang++ 

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Review.cpp

HEAD = Review.hpp

OBJS = $(SRCS:.c = .o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.c:%.o 
	$(CC) -c $< -o $@

all: $(NAME)

fclean: clean
	rm -rf $(NAME)

clean: 
	rm -rf $(NAME)