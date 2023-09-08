#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

// A chaque nouveau caractere trouve par i dans argv[2] :
// On appelle la fonction convert_and_send pour convertir chaque
// octet en bit et envoyer leur signal au pid du serveur.
// La fonction traite donc 8 octets a chaque fois qu'elle est appelee
// et utilise la fonction kill, qui envoie un signal a un serveur grace
// a son PID.
// Le type de signal est specifie par SIGUSR1 et 2, 

static int convert_and_send_signal(int pid, char str)
{
    int i;
    int bit;

	i = 0;
	while (i < 8)
	{
		bit = (str >> i) & 1;
		if (bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
    int i;
    int pid;

    if (argc != 3)
    {
        ft_printf("MAUVAIS FORMAT: ");
        ft_printf("Essaye en mettant ");
        ft_printf("<./client> <le PID du server> <le message a transmettre>\n");
        return (0);
    }
    i = 0;
    pid = ft_atoi(argv[1]);
    while (argv[2][i])
    {
        convert_and_send_signal(pid, argv[2][i]);
        i++;
    }
    if (argv[2][i] == '\0')
		ft_printf("Message envoye :)");
    return(0);
}

