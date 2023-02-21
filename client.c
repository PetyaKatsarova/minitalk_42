/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 17:55:24 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/02/21 18:39:00 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void send_bits(int pid, char ch)
{
	int	i;
	
	i = 0;
	while (i < 8)
	{
		if ((ch & (0x01 << i)) != 0)
			kill(pid, SIGUSR1); // sigusr1 represents 1
		else
			kill(pid, SIGUSR2); // sigusr2 represents 0
		usleep(100);
		i++;
	}	
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	
	i = 0;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i]);
			i++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		printf("\033[91mError: wrong format.\033[0m\n");
		printf("\033[33mTry: ./client <PID> <MESSAGE>\033[0m\n");
		return (1);
	}
	return (0);
}