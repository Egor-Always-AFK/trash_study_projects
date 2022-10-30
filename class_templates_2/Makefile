NAME = employee

CC = clang++ 

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp src/AEmployee.cpp src/Employee.cpp src/Fink.cpp src/Highfink.cpp src/Manager.cpp

HEAD = incl/AEmployee.hpp incl/Employee.hpp incl/Fink.hpp incl/Highfink.hpp incl/Manager.hpp

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