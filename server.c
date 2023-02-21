/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pkatsaro <pkatsaro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 14:59:04 by pkatsaro      #+#    #+#                 */
/*   Updated: 2023/02/21 18:40:59 by pkatsaro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include <stdio.h>
# include <unistd.h>

void receive_bite(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1) // i am a genios: sigusr1 sends 1 , sigusr2 represents 0!!!
		bit |= (0x01 << i); // why is that?? isnt i == to bit x 2?? how do i get the signal: what is sigusr1 and how do i get the bits??? i need a global var!!!
	i++;	
	if (i == 8)
	{
		printf("%c", bit);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	if (argc != 1)
	{
		printf("Error. You dont need args here.");
		return (1);
	}
	pid = getpid();
	printf("SERVER started\nPID: %d\nWaiting for messages...\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, &receive_bite);
		signal(SIGUSR2, &receive_bite);
		pause();
	}
	return (0);
}