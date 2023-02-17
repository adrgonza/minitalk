#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}

void	ft_print_bites(int signal)
{
	static int chr;

	if (signal = SIGUSR1)
		chr = chr + (1 << )
	else
		chr = chr + (0 << );
}

int main()
{
    write(1, "\x1B[33m\n            Server running.\n\nPid number: ", 48);
    ft_putnbr(getpid());
    while(1)
	{
		signal(SIGUSR1, ft_print_bites);
		signal(SIGUSR2, ft_print_bites);
        pause();
	}

}