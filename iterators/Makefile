NAME = friends

CC = clang++ 

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp Friends.cpp 

HEAD = Friends.hpp

OBJS = $(SRCS:.c = .o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.c:%.o 
	$(CC) -c $< -o $@

all: $(NAME)

clean: 
	rm -rf $(NAME)

re: clean all