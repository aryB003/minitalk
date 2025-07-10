/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryan <aryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:51 by aryan             #+#    #+#             */
/*   Updated: 2025/07/10 17:42:51 by aryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	received(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printstr("Message ackowledged by server\n");
	}
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printstr("Usage: ./client <PID> <Message>\n");
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (!ft_isdigit(argv[1][i]))
		{
			ft_printstr("Error: Server PID must only contain digits.\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void send_message(pid_t pid, char* message)
{
	while(1)
	{
		int bitIndex = 7;
		while (bitIndex >= 0)
		{
			int is_0 = (*message & 1 << bitIndex) == 0;
			if (is_0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(400);
			bitIndex--;
		}
		if (*message == '\0')
			break;
		message++;
	}
}

int main( int ac, char **av)
{
    int pid;
	signal(SIGUSR1, received);
	if(!check_input(ac,av))
		return (1);
	pid = ft_atoi(av[1]);
	send_message(pid, av[2]);
}