#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "libft/libft.h"

static void	joli_talk(int pid)
{
	ft_printf("Blip Bloup...\n");
	ft_printf("Voilà mon PID: %d\n", pid); // affiche le pid
	ft_printf("Tu peux écrire ton message bg :)\n");
}

static void	gestionnaire_signal(int signal)
{
	static int	bit; // static pour que la variable conserve sa valeur
	static int	i; // entre les différents appels de la fonction

	if (signal == SIGUSR1 || signal == SIGUSR2)
		i |= (0x01 << bit); // décale cette valeur binaire vers la gauche de "bit" positions
	bit++;
	if (bit == 8) // assez de bit pour composer un caractère à afficher
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	joli_talk(pid);
	while (1) // boucle infinie pour pas avoir a relancer le serveur
		{
			signal(SIGUSR1, gestionnaire_signal); // signal() définit le gestionnaire invoquer
			signal(SIGUSR2, gestionnaire_signal); // en cas de réception d'un signal particulier 
			pause(); // force le processus à s'endormir jusqu'à ce qu'un nouveau signal soit reçu
		}
	return (0);
}
