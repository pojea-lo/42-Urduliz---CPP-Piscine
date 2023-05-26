NAME = PmergeMe

SRC = main.cpp\
 	PmergeMe.cpp

OBJS = $(SRC: .cpp=.o)

CC = c++
 
FLAGS = -Wall -Werror -Wextra -std=c++98
SAN = -g3 -fsanitize=address

RM = rm -r -f

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(SAN)

clean:
	$(RM) *.o *.dSYM

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.phony: name, all, clean, fclean, re
