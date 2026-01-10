# !--Makefile--

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS += -I./header

SRCS = ft_isalnum.c			\
		ft_atoi.c 			\
		ft_itoa.c 			\
		ft_bzero.c			\
		ft_split.c			\
		ft_memcmp.c			\
		ft_memcpy.c 		\
		ft_strchr.c 		\
		ft_substr.c 		\
		ft_strlcat.c 		\
		ft_strncmp.c 		\
		ft_isalpha.c		\
		ft_isprint.c		\
		ft_putchar_fd.c		\
		ft_putendl_fd.c		\
		ft_strlcpy.c		\
		ft_strnstr.c		\
		ft_tolower.c		\
		ft_isascii.c		\
		ft_memcpy.c			\
		ft_putnbr_fd.c		\
		ft_strdup.c 		\
		ft_strlen.c 		\
		ft_strrchr.c		\
		ft_memset.c			\
		ft_toupper.c		\
		ft_calloc.c			\
		ft_isdigit.c		\
		ft_memchr.c			\
		ft_memmove.c		\
		ft_putstr_fd.c		\
		ft_strjoin.c		\
		ft_strmapi.c		\
		ft_strcmp.c			\
		ft_strtrim.c		\
		ft_striteri.c		\
		ft_utils.c			\
		ft_printf.c			\
		ft_utils2.c			\
		ft_support_print.c	\
		ft_lstadd_back.c 	\
		ft_lstadd_front.c 	\
		ft_lstclear.c 		\
        ft_lstdelone.c 		\
		ft_lstlast.c 		\
		ft_lstnew.c			\
        ft_lstsize.c 		\
		ft_lstiter.c 		\
		ft_lstmap.c			\
		get_next_line.c		\
		get_next_line_utils.c	

OBJS = $(SRCS:%.c=%.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
