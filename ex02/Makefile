NAME=PmergeMe
RM= rm -rf
CPP = g++-11
CPPFLAGS =  -std=c++98 -Wall -Wextra -Werror

SRC= main PmergeMe \

OBJ= $(SRC:=.o)

all: $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c $<

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS)  $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all