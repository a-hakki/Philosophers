
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = philo
SOURCES = \
	atoi.c \
	forks.c \
	checks.c \
	init.c \
	main.c \
	routine.c \
	utiles.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJECTS)

