#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

int	g_signal = 0;

static void	receive_signal(int signal)
{
	g_signal = 1;
}

static int	ft_error(const char *msg)
{
	ft_printf("%s\n", msg);
	return (1);
}

static void	send_char(int pid, char c)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = (c >> i) & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_signal != 1)
			;
		g_signal = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	int		len;
	char	*message;

	if (argc != 3)
		return (ft_error("Format incorrect: ./client <PID> <msg>"));
	i = 0;
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (0);
	message = argv[2];
	len = ft_strlen(message);
	signal(SIGUSR1, receive_signal);
	while (i < len)
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}
