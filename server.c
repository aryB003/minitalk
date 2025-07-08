/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryan <aryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:41 by aryan             #+#    #+#             */
/*   Updated: 2025/07/08 19:09:41 by aryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	handle_signal(int sig)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	c <<= 1; 

	if (sig == SIGUSR1)
		c |= 1;  

	bit_count++;

	if (bit_count == 8)
	{
		write(1, &c, 1);  // Print the character
		c = 0;            // Reset for next character
		bit_count = 0;
	}
}

int main(void)
{
    ft_printint(getpid());
	ft_printchar('\n');
    
    signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	while (1)
		pause();  // Wait for incoming signal
	return (0);
}