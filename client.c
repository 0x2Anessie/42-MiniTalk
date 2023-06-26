#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

static int ft_error(int argc, char **argv)
{
    if (argc != 3)
        return (1);
    return (0);
    if (argv);
}

static void send_to_server(int pid, char *str)
{
    int bit;

    kill(pid, SIGUSR1); // permet d'envoyer un signal a un pid
    kill(pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	char    *str;
    int pid;

    if (ft_error(argc, argv))
        return (1);
    str = argv[2];
    pid = ft_atoi(argv[1]);
}
