/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:57:31 by adrgonza          #+#    #+#             */
/*   Updated: 2023/02/19 21:24:52 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_print_char(int signal)
{
	static int	i;
	static int	chr;

	if (signal == SIGUSR1)
		chr = chr << 1 | 1;
	else
		chr = chr << 1;
	if (++i == 8)
	{
		write(1, &chr, 1);
		i = 0;
		chr = 0;
	}
}

int	ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	return (write(1, &nb, 1));
}

int	main(void)
{
	write(1, "\033[0;32m            Server running\n\nPid number: ", 48);
	ft_putnbr(getpid());
	write(1, "\033[0m\n\n", 7);
	signal(SIGUSR1, ft_print_char);
	signal(SIGUSR2, ft_print_char);
	while (1)
		pause();
}
