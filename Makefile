NAME = minitalk.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f

SRCS = client.c server.c

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(AR) $@ $^
	@clear
	@echo "   _____  .__       .__  __         .__   __    ";
	@echo "  /     \ |__| ____ |__|/  |______  |  | |  | __ ";
	@echo " /  \ /  \|  |/    \|  \   __\__  \ |  | |  |/ / ";
	@echo "/    Y    \  |   |  \  ||  |  / __ \|  |_|    < ";
	@echo "\____|__  /__|___|  /__||__| (____  /____/__|_ \ ";
	@echo "        \/        \/              \/          \/ ";

all:
	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
