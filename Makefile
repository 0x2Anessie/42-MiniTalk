NAME_CLIENT	=	client
NAME_SERVER	=	server

CC = cc
CFLAGS = -Wall -Wextra -Werror

all:			$(NAME_CLIENT) $(NAME_SERVER)
				@clear 
				@echo "   _____  .__       .__  __         .__   __    ";
				@echo "  /     \ |__| ____ |__|/  |______  |  | |  | __ ";
				@echo " /  \ /  \|  |/    \|  \   __\__  \ |  | |  |/ / ";
				@echo "/    Y    \  |   |  \  ||  |  / __ \|  |_|    < ";
				@echo "\____|__  /__|___|  /__||__| (____  /____/__|_ \ ";
				@echo "        \/        \/              \/          \/ ";

$(NAME_CLIENT):
				make -C libft/ && mv libft/libft.a .
				$(CC) -o $(NAME_CLIENT) client.c libft.a

$(NAME_SERVER):
				$(CC) -o $(NAME_SERVER) server.c libft.a
								
clean:
				make clean -C libft/
				@clear
				@echo "        /\                __              __                         ";
				@echo "  ____  )/ ____   _______/  |_      ____ |  |   ____  _____    ____   ";
				@echo "/  ___\  /  __ \ /  ___/\   __\   /  ___\|  | /  __ \ \__  \  /    \  ";
				@echo "\  \___  \  ___/ \___ \  |  |     \  \___|  |_\  ___/ / __  \|   |  \ ";
				@echo " \____ >  \____ >_____ > |__|      \____ >____/\____> ____  / ___|  / ";
				@echo "                                                          \/      \/  ";

fclean: 		clean
				rm -rf $(NAME_CLIENT) $(NAME_SERVER) libft.a
				@clear
				@echo "        /\                __        _____       __                         ";
				@echo "  ____  )/ ____   _______/  |_    _/ ____\____ |  |   ____  _____    ____   ";
				@echo "/  ___\  /  __ \ /  ___/\   __\   \  __\/  ___\|  | /  __ \ \__  \  /    \  ";
				@echo "\  \___  \  ___/ \___ \  |  |      |  | \  \___|  |_\  ___/  / __ \|   |  \ ";
				@echo " \____ >  \____> _____ > |__|      |__|  \____ >____/\____ > ____  /___|  / ";
				@echo "                                                                 \/     \/  ";
									
re:				fclean all

.PHONY:			all clean fclean re
