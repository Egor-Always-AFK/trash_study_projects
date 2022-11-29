NAME = service

CC = clang++ 

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp src/AutoService.cpp src/srcs.cpp src/parser.cpp

HEAD = incl/AutoService.h incl/MainHeader.h

OBJS = $(SRCS:.c = .o)

$(NAME) : $(OBJS) $(HEAD)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.c:%.o 
	$(CC) -c $< -o $@

all: $(NAME)

clean: 
	rm -rf $(NAME)

re: clean all