NAME=btc
RM= rm -rf
CPP = c++
CPPFLAGS =  -std=c++98 -Wall -Wextra -Werror

SRC= main BitcoinExchange\

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