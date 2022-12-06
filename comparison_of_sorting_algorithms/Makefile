NAME = sort

CC = clang++ 

CFLAGS = -Wall -Wextra -Werror -g

SRCS = hoares_algorithm.cpp bubble_sort.cpp main.cpp
# SRCS = main.cpp 

HEAD = header.h

OBJS = $(SRCS:.c = .o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.c:%.o 
	$(CC) -c $< -o $@

all: $(NAME)

clean: 
	rm -rf $(NAME)

re: clean all