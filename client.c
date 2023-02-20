/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:57:13 by adrgonza          #+#    #+#             */
/*   Updated: 2023/02/19 21:18:32 by adrgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (write(1, "\033[31mError:\nTry: ./.. 'pid' 'str'", 34));
	i = 0;
	while (argv[1][i])
		if ((argv[1][i++] < '0' || argv[1][i] > '9') || i > 9)
			return (write(1, "\033[31mError: Invalid Pid...\n", 28));
	i = 0;
	while (argv[1][i] >= '0' && argv[1][i] <= '9')
		pid = (argv[1][i++] - '0') + pid * 10;
	while (*argv[2] && pid > 0)
	{
		i = 8;
		while (i--)
		{
			if (*argv[2] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		argv[2]++;
	}
}
