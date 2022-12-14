NAME = service

CC = clang++ 

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp src/AutoService.cpp src/srcs.cpp src/parser.cpp

HEAD = incl/AutoService.h incl/MainHeader.h

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all