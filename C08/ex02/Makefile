NAME = easyfind

SRC = main.cpp\
		mutantstack.cpp\

OBJS = $(SRC: .cpp=.o)

CC = clang++
FLAGS = -Wall -Werror -Wextra
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
