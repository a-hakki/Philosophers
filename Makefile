


all:
	cc -Wall -Wextra -Werror -fsanitize=thread -g3 main.c libft/libft.a -o philo