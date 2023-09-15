#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include "libft/libft.h"

char	g_buffer[BUFFER_SIZE];

static void	handle_received_char(char received_char)
{
	int	current_pos;

	current_pos = ft_strlen(g_buffer);
	if (received_char == '\0')
	{
		write(STDOUT_FILENO, g_buffer, current_pos);
		write(STDOUT_FILENO, "\n", 1);
		g_buffer[0] = '\0';
	}
	else if (current_pos < BUFFER_SIZE - 1)
	{
		g_buffer[current_pos] = received_char;
		g_buffer[current_pos + 1] = '\0';
	}
}

static void	receive_and_print_signal(int signal, siginfo_t *data, void *vp)
{
	static int	bit;
	static char	received_char;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		received_char = received_char | ((signal == SIGUSR1) << bit);
		bit++;
		if (bit == 8)
		{
			handle_received_char(received_char);
			bit = 0;
			received_char = 0;
		}
		kill(data->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_buffer[0] = '\0';
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &receive_and_print_signal;
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}

