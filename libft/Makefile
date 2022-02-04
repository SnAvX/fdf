
NAME = libft.a

SRCS = ft_malloc.c ft_strchrs.c ft_strsubchr.c ft_strncpy.c ft_strnew.c ft_wcounter.c ft_split.c get_next_line.c ft_atoi.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar_fd_return.c ft_itoa_base.c ft_itoa_base_more.c ft_strjoin_f12.c ft_putnbr_unsigned.c


FLAG = -Wall -Werror -Wextra

OUT = a.out 

all: ${NAME}

${NAME}:
	gcc ${FLAG} -c ${SRCS} -I .
	ar rc $(NAME) $(SRCS:.c=.o) $^
	ranlib $(NAME)
	
clean:
	rm -f $(SRCS:.c=.o)	

fclean: clean
	rm -f ${NAME}

re: fclean all
