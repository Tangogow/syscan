NAME    = 	syscan

CC			= 	gcc -w

RM			= 	rm -f

SRC    	= 	src/*.c

OBJ			= 	$(SRC:.c=.o)

INC			=		-I inc

LDFLAGS	=		-L lib -lm -lusb

DEBUG 	=		-g -Wall -Werror -Wextra -Wdouble-promotion -Wpointer-arith

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(INC) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(NAME) $(SRC)/*.o

re:		clean all

debug:
	$(CC) -g -o $(NAME) $(SRC) $(INC) $(CFLAGS) $(LDFLAGS) $(DEBUG)
	@echo "**DEBUG-MOED**"
