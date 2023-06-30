NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME_SERVER): 
	make -C libft/ && mv libft/libft.a .
	$(CC) -o $(NAME_SERVER) server.c libft.a
	@clear
	@echo "   _____  .__       .__  __         .__   __    ";
	@echo "  /     \ |__| ____ |__|/  |______  |  | |  | __ ";
	@echo " /  \ /  \|  |/    \|  \   __\__  \ |  | |  |/ / ";
	@echo "/    Y    \  |   |  \  ||  |  / __ \|  |_|    < ";
	@echo "\____|__  /__|___|  /__||__| (____  /____/__|_ \ ";
	@echo "        \/        \/              \/          \/ ";

all:
	$(NAME_SERVER)

clean:
	make clean -C libft/
	@clear
	@echo "         /\               __             .__                         ";
	@echo "  ____   )/____   _______/  |_      ____ |  |   ____  _____    ____   ";
	@echo "_/ ___\  _/ __ \ /  ___/\   __\   _/ ___\|  | _/ __ \ \__  \  /    \  ";
	@echo "\  \___  \  ___/ \___ \  |  |     \  \___|  |_\  ___/ / __  \|   |  \ ";
	@echo " \____ >  \____ >_____ > |__|      \____ >____/\____> ____  / ___|  / ";
	@echo "                                                          \/      \/  ";

fclean: clean
	rm -f $(NAME_SERVER) libft.a
	@clear
	@echo "         /\               __        _____      .__                         ";
	@echo "  ____   )/____   _______/  |_    _/ ____\____ |  |   ____  _____    ____   ";
	@echo "_/ ___\  _/ __ \ /  ___/\   __\   \   __\/ ___\|  | _/ __ \ \__  \  /    \  ";
	@echo "\  \___  \  ___/ \___ \  |  |      |  | \  \___|  |_\  ___/  / __ \|   |  \ ";
	@echo " \____ >  \____> _____ > |__|      |__|  \____ >____/\____ > ____  /___|  / ";
	@echo "                                                                 \/     \/  ";
re: fclean all

.PHONY: all clean fclean re
