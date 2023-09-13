NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f
Lib_H = libft.h 

SRCS_LIBFT = ft_atoi.c ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_strlen.c

OBJS_LIBFT = $(SRCS_LIBFT:%.c=%.o)

$(NAME): $(OBJS_LIBFT)
	$(AR) $@ $^

all: $(NAME)
    
clean:
	$(RM) $(OBJS_LIBFT)
    
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
