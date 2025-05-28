CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = libft.a
SOURCES = \
		2.printfd/fd_numbers.c \
		2.printfd/fd_pointers.c \
		2.printfd/printfd.c \
		2.printfd/ft_printf.c \
		\
		\
		3.get_next_line/get_next_line.c \
		\
		\
		new/ft_iswhitespace.c \
		new/ft_strchr_index.c \
		new/ft_arrlen.c \
		new/ft_strcmp.c \
		new/ft_strndup.c \
		new/ft_init.c \
		new/ft_free.c \
		new/ft_malloc.c \
		new/int_free.c \
		new/ft_read.c \
		new/lst_new.c \
		new/lst_addback.c \
		new/lst_addfront.c \
		new/lst_clear.c \
		new/lst_last.c \
		new/lst_size.c \
		new/ft_count_char.c \
		new/ft_insert_char.c \
		new/ft_strinsert.c \
		new/ft_strstr.c \
		new/ft_stristr.c \
		new/ft_putarr.c \
		new/ft_lstndup.c \
		new/ft_lstdup.c \
		new/ft_lstgetnode.c \
		new/ft_str2lst.c \
		new/ft_lst2str.c \
		new/ft_lstpop.c \
		new/ft_lstinsert.c \
		new/ft_arr2str.c \
		new/ft_strextract.c \
		new/ft_isspace.c \
		new/ft_strpbrk.c \
		\
		\
		1.base/ft_isalnum.c \
		1.base/ft_isalpha.c \
		1.base/ft_isascii.c \
		1.base/ft_isdigit.c \
		1.base/ft_isprint.c \
		1.base/ft_tolower.c \
		1.base/ft_toupper.c \
		1.base/ft_atoi.c \
		1.base/ft_itoa.c \
		1.base/ft_split.c \
		1.base/ft_strchr.c \
		1.base/ft_strdup.c \
		1.base/ft_striteri.c \
		1.base/ft_strjoin.c \
		1.base/ft_strlcat.c \
		1.base/ft_strlcpy.c \
		1.base/ft_strlen.c \
		1.base/ft_strmapi.c \
		1.base/ft_strncmp.c \
		1.base/ft_strnstr.c \
		1.base/ft_strrchr.c \
		1.base/ft_strtrim.c \
		1.base/ft_substr.c \
		1.base/ft_bzero.c \
		1.base/ft_calloc.c \
		1.base/ft_memchr.c \
		1.base/ft_memcmp.c \
		1.base/ft_memcpy.c \
		1.base/ft_memmove.c \
		1.base/ft_memset.c \
		1.base/ft_putchar_fd.c \
		1.base/ft_putendl_fd.c \
		1.base/ft_putnbr_fd.c \
		1.base/ft_putstr_fd.c \
		1.base/ft_lstadd_back_bonus.c \
		1.base/ft_lstadd_front_bonus.c \
		1.base/ft_lstclear_bonus.c \
		1.base/ft_lstdelone_bonus.c \
		1.base/ft_lstiter_bonus.c \
		1.base/ft_lstlast_bonus.c \
		1.base/ft_lstmap_bonus.c \
		1.base/ft_lstnew_bonus.c \
		1.base/ft_lstsize_bonus.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJECTS)