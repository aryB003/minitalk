/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryan <aryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:51 by aryan             #+#    #+#             */
/*   Updated: 2025/07/08 22:55:35 by aryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	recieved(int sig)
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

int main()
{
    
}